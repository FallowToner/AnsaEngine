FROM ubuntu:22.04

RUN    apt update \
    && apt install -y  git gcc g++ cmake libglfw3-dev libglm-dev libglew-dev libfmt-dev libspdlog-dev libimgui-dev
