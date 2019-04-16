FROM		ubuntu:16.04

RUN			apt-get update -y && \
    		apt-get upgrade -y && \
			apt-get install -y curl openssh-server ca-certificates postfix libssl-dev sudo

#			Создание ssl-ключей
RUN			openssl genrsa -des3 -passout pass:qwerty -out server.pass.key 2048 && \
			openssl rsa -passin pass:qwerty -in server.pass.key -out server.key && \
			rm server.pass.key && \
			openssl req -new -key server.key -out server.csr -subj "/C=UK/ST=Warwickshire/L=Leamington/O=OrgName/OU=IT Department/CN=example.gitlab.com" && \
			openssl x509 -req -days 365 -in server.csr -signkey server.key -out server.crt

WORKDIR		/tmp

#			Распаковка архива gitlab-ce и запуск скрипта
RUN			curl -LO https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh && \
			chmod 777 script.deb.sh && \
			bash script.deb.sh && \
			apt-get install -y gitlab-ce tzdata

WORKDIR		/

#			Настройка https
RUN			sed -i "/external.*/d" /etc/gitlab/gitlab.rb && \
			echo "192.168.99.100 example.gitlab.com example.gitlab.com" >> /etc/hosts && \
			echo "external_url \"https://example.gitlab.com\"" >> /etc/gitlab/gitlab.rb && \
			echo "nginx['ssl_certificate'] = \"/etc/gitlab/ssl/server.crt\""  >> /etc/gitlab/gitlab.rb && \
			echo "nginx['ssl_certificate_key'] = \"/etc/gitlab/ssl/server.key\"" >> /etc/gitlab/gitlab.rb && \
			sed -i "s/# letsencrypt\['enable'\] = nil/letsencrypt\['enable'\] = false/g" /etc/gitlab/gitlab.rb && \ 
			sed -i "s/# nginx\['redirect_http_to_https'\] = false/nginx\['redirect_http_to_https'\] = true/g" /etc/gitlab/gitlab.rb && \
			echo "nginx['redirect_http_to_https'] = 80" >> /etc/gitlab/gitlab.rb && \
			mkdir -p /etc/gitlab/ssl && chmod 700 /etc/gitlab/ssl && \
			cp server.key server.crt /etc/gitlab/ssl

EXPOSE		443 80 22

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null

#	tzdata обеспечивает работу одного из модулей GitLab; установка обязательна
#	tail -f /dev/null - команда, позволяющая держать контейнер запущенным

#	docker build -t ex03 .
#	docker run -dit -p 8022:22 -p 8080:80 -p 8443:443 --privileged ex03
#	http://phase2.github.io/devtools/common-tasks/ssh-into-a-container/