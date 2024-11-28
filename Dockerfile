# Use an official ROS2 base image
FROM osrf/ros:jazzy-desktop-full

SHELL ["/bin/bash", "-c"]

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    git \
    cmake \
    build-essential \
    libboost-all-dev \
    libeigen3-dev \
    libopencv-dev \
    libpcl-dev \
    python3-colcon-common-extensions \
    python3-vcstool \
    libsuitesparse-dev \
    libboost-dev libboost-filesystem-dev \
    libopencv-dev \
    libatlas-base-dev \
    libgoogle-glog-dev \
    gdb \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /root


# Source the workspace
RUN echo "source /opt/ros/$ROS_DISTRO/setup.bash" >> ~/.bashrc
RUN echo "source /root/OKVIS2_ws/install/setup.bash" >> ~/.bashrc