FROM quay.io/zoomer/baseimage:production
MAINTAINER devops@zoomer.io

COPY ansible/ /app/ansible/

WORKDIR /app/ansible

RUN ansible-playbook  -c local playbook.yml
WORKDIR /app
ADD . /app
RUN cmake . && make -j 5 && ldconfig --verbose

ENTRYPOINT ["/sbin/my_init", "--skip-runit"]
