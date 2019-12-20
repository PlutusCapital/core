FROM phusion/baseimage:0.11

ENV LANG=en_US.UTF-8

RUN apt-get update -y

WORKDIR /app

ADD src/plutusd /app
ADD src/plutus-cli /app

ADD entrypoint.sh /app

RUN chmod 777 /app/entrypoint.sh
RUN chmod 777 /app/plutusd
RUN chmod 777 /app/plutus-cli
