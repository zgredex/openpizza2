/* Person_ResumeRouteOrDetach: resumes a person's route or releases it
   (0x50e7d0). */
struct Object {
    int IsVisibleThisFrame();
    void SetState(int state);
};

struct UI {
    void DetachChildRecord();
};

struct Person {
    int CanContinuePath();
    void TruncatePathToCurrentStep();
    void ResumeRouteOrDetach();
};

void Person::ResumeRouteOrDetach()
{
    if (((Object *)this)->IsVisibleThisFrame()) {
        if (CanContinuePath()) {
            TruncatePathToCurrentStep();
            ((Object *)this)->SetState(6);
            return;
        }
        ((UI *)this)->DetachChildRecord();
    }
    ((Object *)this)->SetState(6);
}
