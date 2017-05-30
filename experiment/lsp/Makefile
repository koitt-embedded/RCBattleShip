SRCS = basic_server.c basic_client.c
.SUFFIXES = .c .o

SERVER = basic_server.o
CLIENT = basic_client.o
TARGET = basic_server basic_client

all:	$(TARGET)

basic_server:	$(SERVER)
	$(CC) -o basic_server $(SERVER)

basic_client:	$(CLIENT)
	$(CC) -o basic_client $(CLIENT)

clean:
	rm -rf $(SERVER) $(CLIENT) $(TARGET)
