FROM ubuntu:21.04

RUN apt-get update &&\
    apt-get install -y wget git cmake g++

RUN wget https://raw.githubusercontent.com/ETrobocon/etrobo/master/scripts/startetrobo -O ~/startetrobo && \
    sed -i -r 's/^(\s*)sudo/\1/g' ~/startetrobo && \
    chmod +x ~/startetrobo

RUN git config --global user.name docker && \
    git config --global user.email example@example.com && \
    ~/startetrobo shell

COPY entrypoint.sh /entrypoint.sh

RUN chmod +x /entrypoint.sh && \
    mkdir -p /tmp/etrobocon

ENTRYPOINT ["/entrypoint.sh"]
