FROM	nginx

COPY	index.html		/usr/share/nginx/html/
COPY	default.conf	/etc/nginx/conf.d/
COPY	nginx.key		/etc/ssl/private/
COPY	nginx.crt		/etc/ssl/certs/

#	docker build -t img_snake .
#	docker run -d --name snake -p 5080:80 -p 5443:443 snake