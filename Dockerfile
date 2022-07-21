FROM ubuntu:22.04

RUN    apt update \
    && apt install -y  tar git gcc g++ cmake libglfw3-dev libglm-dev libglew-dev libfmt-dev libspdlog-dev libimgui-dev

COPY ./docker_build.sh /