FROM ubuntu:latest

WORKDIR /homework_build

RUN apt-get update -y && apt-get install -y build-essential cmake ninja-build

COPY . .

RUN ls -1a && \
    mkdir 01_1/build && \
    cmake -G Ninja -S 01_1 -B 01_1/build
