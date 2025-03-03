# Microservice architecture
## Introduction
- A style that structures an app as a collection of loosely coupled services. This means that each service has a job, and it only does that. one service can not work, while others work. This makes apps made with this architecture more scalable, flexible, and easier to maintain. 
- Each service is a thing on its own. Its tested on its own, it is deployed on its own, and written in its own technology, this means that different services can be written in completly different langauges and technices, but if they have the same communication protocol, they will be able to work together. Each service has its own database
## Componenets
- Each component does something. There are actual service component, for eaxmple, a user component that is responsible for login, registration and user stuff. On the other side, there are many utility components that do stuff behind the curtains.
### Service Discovery
- This is a component that helps services identify and communicate with eachother. It is maintaining a registry of services and instances. SO its database is a database of services, and their network locations, so other services can find them.
- This can be implemented with a tool called Eureka, or Consul
### API Gateway
- This is a component responsible for API calls, so in communicates with other services when it gets a call, and also returns the result. this components helps in Load balancing, Security, Routing. This is an entry point to the microservices. 
- This ensures that only authenticated requests are forwarded into microservices, and that requests are evenly distributed between microservices, and that a client gets a good response.
- Example: A client wants to get a user profile: The API gatway needs to collect info from the user service to get user info, posts service to get posts from a user, and a comment service to get comments from a user.
### Load balancer
- It distributes all network trafic do different servers so no server is overwhelmed.
- This is done with Nginx, or HAProxy
### Communication
- Services communicate in a way that all of them know. Then can communicate with sync messages, that is done with a REST protocol, or with async messages, which can be done in Kafka, or ReabbitMQ

## Properties
- Microservices allow different parts of the app to scale on their own, which means that the whole system is more scalable, and can be scaled with less resoursces
- They are great for teamwork. Different people can work in different technologies, and at the same time, and not affect eachother in any way, as long as they comlpy to the communication protocol
- If one service fails, others still work. This means its easier to isolate an error
- System with this architecture is complex, and service amangement is harder than when the system is just one big block.
- System requires that that services communicate through a network, which means that network latency can become a problem
- Deploying many services and orchestrating them can be complex, and there are tools that are just for this
- There are tools (Jenkins, GitLab) that are used to automate deployment process. The use CI/CD pipelines