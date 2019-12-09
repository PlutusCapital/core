FROM phusion/baseimage:0.11

ENV LANG=en_US.UTF-8

RUN apt-get update -y

WORKDIR /app

ADD src/pivxd /app
ADD src/pivx-cli /app

ADD entrypoint.sh /app

RUN chmod 777 /app/entrypoint.sh
RUN chmod 777 /app/pivxd
RUN chmod 777 /app/pivx-cli
