TARGET = mp_server basic_client

all: $(TARGET)

mp_server: mp_server.o
	$(CC) -o $@ mp_server.o

basic_client: basic_client.o
	$(CC) -o $@ basic_client.o

clean:
	rm -rf $(TARGET)
	rm -rf *.o
