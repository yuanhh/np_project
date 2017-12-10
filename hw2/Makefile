CC = gcc
CFLAGS = -g -Wall -I$(INC_DIR)
INC_DIR = include
OBJ_DIR = obj

SERVER = server
SRV_SOURCE = inet.c process.c str.c shm.c
SRV_HEADER = $(patsubst %.c, $(INC_DIR)/%.h, $(SRV_SOURCE))
SRV_OBJECT = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRV_SOURCE))

RAS = ras
RAS_SOURCE = inet.c process.c str.c shm.c
RAS_HEADER = $(patsubst %.c, $(INC_DIR)/%.h, $(RAS_SOURCE))
RAS_OBJECT = $(patsubst %.c, $(OBJ_DIR)/%.o, $(RAS_SOURCE))

CLIENT = client
CLIENT_SOURCE = client.c

all: dirs $(SERVER) $(RAS) $(CLIENT)

dirs:
	mkdir -p obj

$(CLIENT): $(CLIENT_SOURCE)
	$(CC) -o $@ $^ $(CFLAGS)

$(SERVER): $(SRV_OBJECT) $(SRV_HEADER)
	$(CC) -o $@ $^ server.c $(CFLAGS)

$(RAS): $(RAS_OBJECT) $(RAS_HEADER)
	$(CC) -o $@ $^ ras.c $(CFLAGS)

$(OBJ_DIR)/%.o: %.c $(INC_DIR)/%.h
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm server
	rm ras
	rm client
