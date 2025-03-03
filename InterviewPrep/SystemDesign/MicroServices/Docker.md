# Docker
- Its a platform that automated deployment of applications inside portable containers. This ensures that an application runs consistently regardless of the environment, because it the dependencies anre configurations of the app are packed in the container as well
- Container is a standalone executable software that includes everything needed to runa piece of software. For example, python application and requirements.txt that we got from venv
- Image is a read only template used to create containers. You need to write a Dockerfile, from which the Docker images are built. Images have layers, and each layer is an instruction from the docker file
- Dockerfile is a file that has instructions on how to build an image.
- Docker Engine is a platform that allows containers to run on host OS
- Docker Hub is cloud based registry used for sharing container images
```
# Example docker file for Node app

# Use Node.js runtime as the base image
FROM node:14

# set WORKDIR
WORKDIR /usr/src/aplikacija/

# copy package.json and install all the dependencies
COPY package*.json ./
RUN npm install

# Copy the rest of the app code
COPY . .

# Expose the app port
EXPOSE 8080

# How to run the application
CMD ["node", "app.js"]
```
- When you write something like this, you can use the build command to create an image:
```
docker build -t aplikacija .
```
- Now that you have an image, you can create and start a container fromt his image with a run command
```
docker run -d -p 8080:8080 aplikacija
```
- Some other docker commands that are user often:
```
# List running container / add -a for all containers
docker ps
# Stop a container so it doesnt run anymore
docker stop <container_id>
# Remove a container so it doesnt exist anymore
docker rm <container_id>
# Remove an image
docker rmi <image_id>
```
- Docker volumes are used to save and persist the data used in containers, something like the disc in a computer.
Some commands for volumes are:
```
# Create a volume
docker volume create <volume_name>
# Mount a volume, connect it to container
docker run -d -v <volume_name>:/data <app_name>
# List existing volumes
docker volume ls
# Remove a volume
docker volume rm <volume_name>
```
- Docker compose is a tool for running multile container aplications. So lets say that 1 container is frontend, and other is backend, you want to run them both. This is managed with YAML file in which you write what you need
- Example YAML file:
```yaml
version: '3.8'

services:
    mongodb:
        image: mongo:latest
        container_name: mongodb
        ports:
            - "27017:27017"
        volumes:
            - mongo-data:/data/db
        networks:
            - backend-network 
  backend:
    image: node:14
    container_name: backend
    working_dir: /usr/src/app
    volumes:
      - ./backend:/usr/src/app
    environment:
      - MONGO_URI=mongodb://mongodb:27017/mydatabase
      - REDIS_HOST=redis
    depends_on:
      - mongodb
      - redis
    networks:
      - backend-network

  frontend:
    image: node:14
    container_name: frontend
    working_dir: /usr/src/app
    volumes:
      - ./frontend:/usr/src/app
    command: sh -c "npm install && npm start"
    ports:
      - "4200:4200"
    networks:
      - frontend-network
```
- To un these services, you need to use docker compose commands, so to start and stop:
```bash
docker-compose up --build
docker-compose down
```