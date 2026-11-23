/* Native Bink 1 decoder: FFmpeg demux/codec + SDL queued audio + Vulkan quads.
 * This is NOT a BinkGetSummary/BinkCopyToBuffer compatibility shim.
 * It consumes compressed bytes directly from the extracted PAK entry.
 */
#include "pc2_movie.h"
#include <SDL2/SDL.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libavutil/channel_layout.h>
#include <libavutil/error.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct movie_memory {
    const uint8_t *data;
    size_t size;
    size_t pos;
};
struct pc2_movie {
    struct movie_memory memory;
    AVIOContext *io;
    AVFormatContext *format;
    AVCodecContext *video, *audio;
    AVFrame *vf, *af;
    AVPacket *pending_video;
    struct SwsContext *scaler;
    SwrContext *resampler;
    SDL_AudioDeviceID audio_device;
    uint8_t *rgba;
    uint32_t width, height;
    int video_stream, audio_stream;
    int sent_eof, done;
    int64_t frames;
    double first_pts;
    uint64_t started_ms;
    double fallback_fps;
    pc2_vk_texture *gpu_texture;
    uint32_t gpu_width, gpu_height;
    char error[256];
};
const char *pc2_movie_error(const pc2_movie *m) { return m ? m->error : "null movie"; }
static int movie_fail(pc2_movie *m,const char *label,int err) {
    char desc[128]; av_strerror(err,desc,sizeof desc);
    snprintf(m->error,sizeof m->error,"%s: %s",label,desc);
    fprintf(stderr,"[pc2-bink] %s\n",m->error);
    return -1;
}
static int read_bytes(void *opaque,uint8_t *buf,int size) {
    struct movie_memory *p=opaque;
    if (size<=0) return AVERROR(EINVAL);
    if (p->pos>=p->size) return AVERROR_EOF;
    size_t n=(size_t)size;
    if (n>p->size-p->pos) n=p->size-p->pos;
    memcpy(buf,p->data+p->pos,n);p->pos+=n;
    return (int)n;
}
static int64_t seek_bytes(void *opaque,int64_t pos,int whence) {
    struct movie_memory *p=opaque;
    if (whence==AVSEEK_SIZE) return p->size>INT64_MAX?AVERROR(EOVERFLOW):(int64_t)p->size;
    int base=whence&~AVSEEK_FORCE;
    int64_t start;
    if (base==SEEK_SET) start=0;
    else if (base==SEEK_CUR) start=(int64_t)p->pos;
    else if (base==SEEK_END) start=(int64_t)p->size;
    else return AVERROR(EINVAL);
    if (pos<0 && start < -pos) return AVERROR(EINVAL);
    if (pos>0 && start>INT64_MAX-pos) return AVERROR(EINVAL);
    int64_t dest=start+pos;
    if (dest<0 || (uint64_t)dest>p->size) return AVERROR(EINVAL);
    p->pos=(size_t)dest;return dest;
}
static AVCodecContext *open_decoder(AVFormatContext *fmt,int idx) {
    const AVCodecParameters *par=fmt->streams[idx]->codecpar;
    const AVCodec *decoder=avcodec_find_decoder(par->codec_id);
    if (!decoder) return NULL;
    AVCodecContext *context=avcodec_alloc_context3(decoder);
    if (!context) return NULL;
    if (avcodec_parameters_to_context(context,par)<0 || avcodec_open2(context,decoder,NULL)<0) {
        avcodec_free_context(&context);return NULL;
    }
    return context;
}
static int audio_open(pc2_movie *m) {
    if (!m->audio || !m->audio->sample_rate) return 1;
    SDL_AudioSpec want={0};
    want.freq=48000;want.format=AUDIO_F32SYS;want.channels=2;want.samples=2048;
    m->audio_device=SDL_OpenAudioDevice(NULL,0,&want,NULL,0);
    if (!m->audio_device) {
        fprintf(stderr,"[pc2-bink] SDL audio unavailable: %s (video continues)\n",SDL_GetError());
        return 1;
    }
    AVChannelLayout stereo;
    av_channel_layout_default(&stereo,2);
    int rc=swr_alloc_set_opts2(&m->resampler,&stereo,AV_SAMPLE_FMT_FLT,48000,
                               &m->audio->ch_layout,m->audio->sample_fmt,
                               m->audio->sample_rate,0,NULL);
    av_channel_layout_uninit(&stereo);
    if (rc<0 || !m->resampler || swr_init(m->resampler)<0) {
        fprintf(stderr,"[pc2-bink] resampler initialization failed (video continues)\n");
        swr_free(&m->resampler);
        SDL_CloseAudioDevice(m->audio_device);m->audio_device=0;
        return 1;
    }
    SDL_PauseAudioDevice(m->audio_device,0);
    return 1;
}
pc2_movie *pc2_movie_open_memory(const uint8_t *bytes,size_t length) {
    if (!bytes||length<32||length>INT64_MAX) return NULL;
    pc2_movie *m=calloc(1,sizeof *m);
    if (!m) return NULL;
    m->memory.data=bytes;m->memory.size=length;
    m->video_stream=-1;m->audio_stream=-1;m->first_pts=-1;
    uint8_t *io_buffer=av_malloc(32768);
    if (!io_buffer) goto bad;
    m->io=avio_alloc_context(io_buffer,32768,0,&m->memory,read_bytes,NULL,seek_bytes);
    if (!m->io) {av_free(io_buffer);goto bad;}
    m->format=avformat_alloc_context();
    if (!m->format) goto bad;
    m->format->pb=m->io;
    m->format->flags|=AVFMT_FLAG_CUSTOM_IO;
    int rc=avformat_open_input(&m->format,NULL,NULL,NULL);
    if (rc<0) {movie_fail(m,"Bink demux open",rc);goto bad;}
    rc=avformat_find_stream_info(m->format,NULL);
    if (rc<0) {movie_fail(m,"Bink stream info",rc);goto bad;}
    for (unsigned i=0;i<m->format->nb_streams;++i) {
        enum AVMediaType type=m->format->streams[i]->codecpar->codec_type;
        if (type==AVMEDIA_TYPE_VIDEO && m->video_stream<0) m->video_stream=(int)i;
        if (type==AVMEDIA_TYPE_AUDIO && m->audio_stream<0) m->audio_stream=(int)i;
    }
    if (m->video_stream<0) {snprintf(m->error,sizeof m->error,"no video stream");goto bad;}
    m->video=open_decoder(m->format,m->video_stream);
    if (!m->video) {snprintf(m->error,sizeof m->error,"no FFmpeg decoder for this Bink video variant");goto bad;}
    m->vf=av_frame_alloc();m->af=av_frame_alloc();
    if (!m->vf || !m->af) goto bad;
    AVRational fps=av_guess_frame_rate(m->format,m->format->streams[m->video_stream],NULL);
    m->fallback_fps=(fps.num>0&&fps.den>0)?av_q2d(fps):15.0;
    if (m->audio_stream>=0) {
        m->audio=open_decoder(m->format,m->audio_stream);
        if (m->audio) audio_open(m);
    }
    fprintf(stderr,"[pc2-bink] FFmpeg opened video %dx%d, fps %.3f, audio %s\n",
            m->video->width,m->video->height,m->fallback_fps,m->audio?"yes":"no");
    return m;
bad:
    if (m->error[0]) fprintf(stderr,"[pc2-bink] %s\n",m->error);
    pc2_movie_close(m);
    return NULL;
}
static void audio_drain(pc2_movie *m) {
    if (!m->audio || !m->audio_device || !m->resampler) return;
    while (avcodec_receive_frame(m->audio,m->af)==0) {
        int max=swr_get_out_samples(m->resampler,m->af->nb_samples);
        if (max<=0 || max>48000*10) {av_frame_unref(m->af);continue;}
        float *out=malloc((size_t)max*2*sizeof(float));
        if (out) {
            uint8_t *dst=(uint8_t*)out;
            int count=swr_convert(m->resampler,&dst,max,
                    (const uint8_t**)m->af->extended_data,m->af->nb_samples);
            if (count>0) SDL_QueueAudio(m->audio_device,out,(uint32_t)count*2*sizeof(float));
            free(out);
        }
        av_frame_unref(m->af);
    }
}
static int convert_video(pc2_movie *m) {
    const int w=m->vf->width,h=m->vf->height;
    if (w<=0||h<=0||w>8192||h>8192) return movie_fail(m,"invalid frame size",AVERROR(EINVAL));
    if ((uint32_t)w!=m->width||(uint32_t)h!=m->height) {
        free(m->rgba);m->rgba=NULL;
        m->rgba=malloc((size_t)w*h*4);
        if (!m->rgba) return movie_fail(m,"RGBA allocation",AVERROR(ENOMEM));
        m->width=(uint32_t)w;m->height=(uint32_t)h;
    }
    m->scaler=sws_getCachedContext(m->scaler,w,h,(enum AVPixelFormat)m->vf->format,
         w,h,AV_PIX_FMT_RGBA,SWS_BILINEAR,NULL,NULL,NULL);
    if (!m->scaler) return movie_fail(m,"pixel format conversion",AVERROR(EINVAL));
    uint8_t *dst[4]={m->rgba,NULL,NULL,NULL};
    int stride[4]={w*4,0,0,0};
    sws_scale(m->scaler,(const uint8_t* const*)m->vf->data,m->vf->linesize,
              0,h,dst,stride);
    return 1;
}
int pc2_movie_next(pc2_movie *m,const uint8_t **rgba,uint32_t *w,uint32_t *h,double *pts) {
    if (!m||!rgba||!w||!h||!pts) return -1;
    if (m->done) return 0;
    for (;;) {
        int rc=avcodec_receive_frame(m->video,m->vf);
        if (rc==0) {
            if (convert_video(m)<0) return -1;
            int64_t best=m->vf->best_effort_timestamp;
            double seconds=(best==AV_NOPTS_VALUE)?((double)m->frames/m->fallback_fps):
                best*av_q2d(m->format->streams[m->video_stream]->time_base);
            if (m->first_pts<0) m->first_pts=seconds;
            *pts=seconds-m->first_pts;
            if (*pts<0) *pts=0;
            *rgba=m->rgba;*w=m->width;*h=m->height;
            m->frames++;
            av_frame_unref(m->vf);
            return 1;
        }
        if (rc==AVERROR_EOF) {m->done=1;return 0;}
        if (rc!=AVERROR(EAGAIN)) return movie_fail(m,"video frame receive",rc);
        if (m->sent_eof) {m->done=1;return 0;}
        if (m->pending_video) {
            rc=avcodec_send_packet(m->video,m->pending_video);
            if (rc==AVERROR(EAGAIN)) continue;
            av_packet_free(&m->pending_video);
            if (rc<0) return movie_fail(m,"pending video packet",rc);
            continue;
        }
        AVPacket *packet=av_packet_alloc();
        if (!packet) return movie_fail(m,"packet allocation",AVERROR(ENOMEM));
        rc=av_read_frame(m->format,packet);
        if (rc==AVERROR_EOF) {
            avcodec_send_packet(m->video,NULL);
            if (m->audio) {avcodec_send_packet(m->audio,NULL);audio_drain(m);}
            m->sent_eof=1;
            av_packet_free(&packet);
            continue;
        }
        if (rc<0) {av_packet_free(&packet);return movie_fail(m,"demux read",rc);}
        if (packet->stream_index==m->video_stream) {
            rc=avcodec_send_packet(m->video,packet);
            if (rc==AVERROR(EAGAIN)) {
                m->pending_video=packet;
                packet=NULL;
            } else if (rc<0) {
                av_packet_free(&packet);return movie_fail(m,"video packet",rc);
            }
        } else if (packet->stream_index==m->audio_stream && m->audio) {
            rc=avcodec_send_packet(m->audio,packet);
            if (rc==AVERROR(EAGAIN)) {
                audio_drain(m);
                rc=avcodec_send_packet(m->audio,packet);
            }
            if (rc>=0) audio_drain(m);
        }
        av_packet_free(&packet);
    }
}
int pc2_movie_draw(pc2_movie *m,pc2_vk *r,const uint8_t *rgba,uint32_t w,uint32_t h) {
    if (!m||!r||!rgba||!w||!h) return 0;
    if (!m->gpu_texture||m->gpu_width!=w||m->gpu_height!=h) {
        if (m->gpu_texture) pc2_vk_texture_destroy(r,m->gpu_texture);
        m->gpu_texture=pc2_vk_texture_create(r,w,h,rgba,w*4u);
        m->gpu_width=w;m->gpu_height=h;
    } else if (!pc2_vk_texture_update(r,m->gpu_texture,rgba,w*4u)) return 0;
    if (!m->gpu_texture || !pc2_vk_begin(r,0,0,0,1)) return 0;
    float sx=800.0f/(float)w,sy=600.0f/(float)h;
    float scale=sx<sy?sx:sy;
    float dw=w*scale,dh=h*scale;
    pc2_vk_draw(r,m->gpu_texture,(800.0f-dw)*0.5f,(600.0f-dh)*0.5f,dw,dh,
                0,0,1,1,0,0,800,600);
    return pc2_vk_end(r);
}
void pc2_movie_reset_clock(pc2_movie *m) {if(m) m->started_ms=SDL_GetTicks64();}
double pc2_movie_clock(const pc2_movie *m) {
    return m&&m->started_ms?(double)(SDL_GetTicks64()-m->started_ms)/1000.0:0.0;
}
void pc2_movie_close(pc2_movie *m) {
    if (!m) return;
    /* GPU video texture is owned by the renderer. Call pc2_movie_release_gpu before
       renderer shutdown when playback is stopped; see below helper. */
    if (m->audio_device) {SDL_ClearQueuedAudio(m->audio_device);SDL_CloseAudioDevice(m->audio_device);}
    swr_free(&m->resampler);
    sws_freeContext(m->scaler);
    avcodec_free_context(&m->audio);avcodec_free_context(&m->video);
    av_frame_free(&m->vf);av_frame_free(&m->af);
    av_packet_free(&m->pending_video);
    avformat_close_input(&m->format);
    if (m->io) avio_context_free(&m->io);
    free(m->rgba);
    free(m);
}
void pc2_movie_release_gpu(pc2_movie *m,pc2_vk *renderer) {
    if (!m||!renderer) return;
    if (m->gpu_texture) pc2_vk_texture_destroy(renderer,m->gpu_texture);
    m->gpu_texture=NULL;m->gpu_width=0;m->gpu_height=0;
}
