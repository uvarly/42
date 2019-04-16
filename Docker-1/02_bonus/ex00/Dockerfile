FROM	nginx

COPY	index.html /usr/share/nginx/html

RUN		apt-get update -y && \
		apt-get upgrade -y && \
		apt-get install -y openssl sudo

# RUN		openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=RU/ST=Moscow Region/L=Moscow/O=42/OU=student/CN=snake.com" && \
# 		sudo openssl dhparam -out /etc/ssl/certs/dhparam.pem 1024 && \
# 		echo "server {\n\tlisten 443 ssl;\n\tlisten [::]:443 ssl;\n\tserver_name localhost;\n\n\tssl_certificate /etc/ssl/certs/nginx-selfsigned.crt;\n\tssl_certificate_key /etc/ssl/private/nginx-selfsigned.key;\n\tssl_dhparam /etc/ssl/certs/dhparam.pem;\n\n\troot /usr/share/nginx/html;\n\tindex index.html index.htm;\n}" >> /etc/nginx/conf.d/default.conf && \
# 		sed -i /etc/nginx/conf.d/default.conf

# EXPOSE	443

#	docker build -t img_snake .
#	docker run -d --name snake --restart always -p 5000:80 img_snake