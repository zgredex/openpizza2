#!/bin/sh
# Fastest way to play Pizza Connection 2 on this machine.
#
# This runs the original Windows executable under Wine. It is not the
# reconstructed C build; it is the shortest path to a playable game while the
# reconstruction continues in parallel.
set -eu

cd "$(dirname "$0")/game"
exec env WINEDEBUG=-all wine fastfood2.exe "$@"
