ARG IMAGE="libfyaml:latest"
FROM ${IMAGE}
# configure argument
ARG CONFIG_ARGS
ENV CONFIG_ARGS=${CONFIG_ARGS:--enable-debug --prefix=/usr}
COPY . /build
WORKDIR /build
# do a maintainer clean if the directory was unclean (it can fail)
RUN make maintainer-clean >/dev/null 2>&1|| true
RUN ./bootstrap.sh 2>&1
RUN ./configure 2>&1 ${CONFIG_ARGS}
RUN make
