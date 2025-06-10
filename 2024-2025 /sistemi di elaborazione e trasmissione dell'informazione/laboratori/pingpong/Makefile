#CC = clang
CFLAGS = -Ipingpong_lib
#CFLAGS = -DDEBUG -g3 -O0 -Ipingpong_lib

SRC = src
BIN_DIR = bin
DATA_DIR = data

LDFLAGS = -L$(BIN_DIR) -lpingpong -lrt
PINGPONG_LIB=$(BIN_DIR)/libpingpong.a
PONG = $(BIN_DIR)/pong_server
UDP_PING = $(BIN_DIR)/udp_ping
TCP_PING = $(BIN_DIR)/tcp_ping
PONG_OBJS = $(BIN_DIR)/pong_server.o
UDP_PING_OBJS = $(BIN_DIR)/udp_ping.o
TCP_PING_OBJS = $(BIN_DIR)/tcp_ping.o

EXECS = $(PONG) $(UDP_PING) $(TCP_PING)

all: $(EXECS)

.PHONY: clean tgz tgz-full

$(EXECS): | $(DATA_DIR)

# Common library
$(PINGPONG_LIB): $(BIN_DIR)/fail.o $(BIN_DIR)/readwrite.o $(BIN_DIR)/statistics.o | $(BIN_DIR)
	ar rcs $@ $(BIN_DIR)/*.o

$(BIN_DIR)/fail.o: $(SRC)/pingpong.h $(SRC)/fail.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c -o $@ $(SRC)/fail.c

$(BIN_DIR)/readwrite.o: $(SRC)/pingpong.h $(SRC)/readwrite.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c -o $@ $(SRC)/readwrite.c

$(BIN_DIR)/statistics.o: $(SRC)/pingpong.h $(SRC)/statistics.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c -o $@ $(SRC)/statistics.c

# Pong server
$(PONG): $(PONG_OBJS) $(PINGPONG_LIB) | $(BIN_DIR)
	$(CC) -o $@ $(PONG_OBJS) $(LDFLAGS)

$(BIN_DIR)/pong_server.o: $(SRC)/pingpong.h $(SRC)/pong_server.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c -o $@ $(SRC)/pong_server.c

# UDP Ping client
$(UDP_PING): $(UDP_PING_OBJS) $(PINGPONG_LIB) | $(BIN_DIR)
	$(CC) -o $@ $(UDP_PING_OBJS) $(LDFLAGS)

$(BIN_DIR)/udp_ping.o: $(SRC)/pingpong.h $(SRC)/udp_ping.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c -o $@ $(SRC)/udp_ping.c

# TCP Ping client
$(TCP_PING): $(TCP_PING_OBJS) $(PINGPONG_LIB) | $(BIN_DIR)
	$(CC) -o $@ $(TCP_PING_OBJS) $(LDFLAGS)

$(BIN_DIR)/tcp_ping.o: $(SRC)/pingpong.h $(SRC)/tcp_ping.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c -o $@ $(SRC)/tcp_ping.c

# Directories
$(BIN_DIR):
	mkdir $(BIN_DIR)

$(DATA_DIR):
	mkdir $(DATA_DIR)

# Utilities
clean:
	rm -f $(BIN_DIR)/*.o $(EXECS) $(PINGPONG_LIB)

tgz: clean
	cd ..; tar cvzf pingpong.tgz --exclude='pingpong/.idea' pingpong

tgz-full: clean
	cd ..; tar cvzf pingpong-full.tgz --exclude='pingpong-full/.idea' pingpong-full

