ARG ALPHINE_VERSION=3.12

FROM alpine:${ALPHINE_VERSION} AS builder

ARG UWEBSOCKETS_VER=f99f20faa95ff5094fb37965521092dd6938ee87

WORKDIR /src

ADD . .

RUN apk add git zlib-dev build-base cmake

RUN git clone https://github.com/uNetworking/uWebSockets.git && \
    cd uWebSockets && \
    git submodule init && \
    git submodule update && \
    git checkout ${UWEBSOCKETS_VER} && \
    make && \
    make install

RUN cd uSockets && \
    make && \
    cd .. && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make

FROM alpine:${ALPHINE_VERSION}

WORKDIR /app

RUN apk add zlib libstdc++

COPY --from=builder /src/build/nitomoe .

CMD ["/app/nitomoe"]