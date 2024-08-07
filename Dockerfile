ARG BASIS=ubuntu:jammy
FROM $BASIS

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    cmake \
    curl \
    g++ \
    make \
    libxerces-c-dev \
    libssl-dev \
    perl-base \
    perl-modules \
    git

ADD . /opt/OpenDDS

ARG ACE_CONFIG_OPTION="--doc-group"
RUN cd /opt/OpenDDS && \
    ./configure --prefix=/usr/local --security ${ACE_CONFIG_OPTION} && \
    ./tools/scripts/show_build_config.pl && \
    make && \
    make install && \
    ldconfig && \
    . /opt/OpenDDS/setenv.sh && \
    cp -a ${MPC_ROOT} /usr/local/share/MPC

ENV ACE_ROOT=/usr/local/share/ace \
    TAO_ROOT=/usr/local/share/tao \
    DDS_ROOT=/usr/local/share/dds \
    MPC_ROOT=/usr/local/share/MPC

WORKDIR /opt/workspace
