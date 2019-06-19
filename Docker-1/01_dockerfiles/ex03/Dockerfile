FROM		ubuntu:16.04

RUN			apt-get update -y	&&	\
			apt-get upgrade -y	&&	\
			apt-get install -y ca-certificates openssh-server curl postfix tzdata sudo	&&	\
			curl -LO https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh	&&	\
			chmod 777 script.deb.sh	&&	\
			./script.deb.sh	&&	\
			apt-get install -y gitlab-ce

RUN			mkdir -p /etc/ssl/certs		&&	\
			mkdir -p /etc/gitlab/ssl	&&	\
			mkdir -p /run/sshd

RUN			openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/C=RU/ST=MR/L=Moscow/O=42/OU=21/CN=192.168.99.100" -keyout /etc/gitlab/ssl/key.key -out /etc/gitlab/ssl/cert.crt	&&	\
			sed -i	"/external_url.*/d"															/etc/gitlab/gitlab.rb	&&	\
			echo	"nginx['ssl_certificate']				= \"/etc/gitlab/ssl/cert.crt\""	>>	/etc/gitlab/gitlab.rb	&&	\
			echo	"nginx['ssl_certificate_key']			= \"/etc/gitlab/ssl/key.key\""	>>	/etc/gitlab/gitlab.rb	&&	\
			echo	"nginx['redirect_http_to_https']		= true"							>>	/etc/gitlab/gitlab.rb	&&	\
			echo	"nginx['redirect_http_to_https_port']	= 80"							>>	/etc/gitlab/gitlab.rb	&&	\
			echo	"letsencrypt['enable']					= false"						>>	/etc/gitlab/gitlab.rb	&&	\
			echo	"external_url 'https://192.168.99.100'"									>>	/etc/gitlab/gitlab.rb	&&	\
			echo	"gitlab_rails['gitlab_ssh_host']		= '192.168.99.100'"				>>	/etc/gitlab/gitlab.rb	&&	\
			echo	"gitlab_rails['gitlab_shell_ssh_port']	= 2244"							>>	/etc/gitlab/gitlab.rb	&&	\
			echo	"Port 2244"																>>	/etc/ssh/ssh_config		&&	\
			echo	"Port 2244"																>>	/etc/ssh/sshd_config

EXPOSE		443 80 22 2244

ENTRYPOINT	/usr/sbin/sshd	&&	\
			(/opt/gitlab/embedded/bin/runsvdir-start &)	&&	\
			gitlab-ctl reconfigure	&&	\
			tail -f /dev/null

#	docker build -t ex03 .
#	docker run -dit --rm -P -p 8443:443 -p 2244:2244 ex03