#CC=clang
CFLAGS= -DHTML_301='"301_Moved_Permanently.html"' \
        -DHTML_403='"403_Forbidden.html"' \
        -DHTML_404='"404_Not_Found.html"' \
        -DHTML_500='"500_Internal_Error.html"' \
        -DHTML_501='"501_Method_Not_Implemented.html"' \
	-DDEBUG \
	# -DINCaPACHE_8_1 \
	# -g3 -O0 -Wall -pedantic \
	# -DPRETEND_TO_BE_ROOT \
        -DIMAGE='"uncadunca.jpg"' \
        -DSTYLE='"000_style.css"'
OBJS=incApache_aux.o incApache_http.o incApache_main.o incApache_threads.o
BIN_DIR=bin
EXE=$(BIN_DIR)/incapache

.PHONY: clean tgz

all: $(EXE)

$(EXE): $(OBJS) $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) -lpthread
	sudo chown root $(EXE)
	sudo chmod u+s $(EXE)

incApache_aux.o: incApache_aux.c incApache.h
incApache_http.o: incApache_http.c incApache.h
incApache_main.o: incApache_main.c incApache.h
incApache_threads.o: incApache_threads.c incApache.h

clean:
	rm -f $(OBJS) $(EXE)

tgz: clean
	cd .. ; tar cvzf incapache-students.tgz --exclude=incapache-students/bin/Debug --exclude=incapache-students/.idea incapache-students

$(BIN_DIR):
	mkdir -p $(BIN_DIR)


