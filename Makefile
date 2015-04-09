
team-number=5122


# Build information
OUT=FRCUserProgram
# src.dir=src
# build.dir=build
# out.exe=Debug/${out}

# Deployment information
username=lvuser
password=
deploy.dir=/home/lvuser
deploy.kill.command=/usr/local/frc/bin/frcKillRobot.sh -t -r
command.dir=/home/lvuser/

# Libraries to use
# wpilib=${user.home}/wpilib/cpp/${cpp-version}
# wpilib.lib=${wpilib}/lib
# roboRIOAllowedImages=23
WPILIB = C:\Users\R2D2/wpilib

#tools
CXX=arm-frc-linux-gnueabi-g++

#vars
SRCDIR = src
OBJDIR = dist
BINDIR = bin
SRCS = $(wildcard $(SRCDIR)/*.cpp) \
	$(wildcard $(SRCDIR)/Commands/*.cpp) \
	$(wildcard $(SRCDIR)/Subsystems/*.cpp)


# OBJS = $(SRCS:%.cpp=%.o)
OBJS = $(SRCS:src/%.cpp=%.o)
# OBJS = $(notdir $(SRCS:%.cpp=%.o))

TARGET = FRCUserProgram
CPPFLAGS = -std=c++1y -I"$(WPILIB)/cpp/current/include" -I"$(SRCDIR)" -O0 -g3 -Wall -c -fmessage-length=0
LDFLAGS = -L$(WPILIB)/cpp/current/lib -Wl,-rpath,/opt/GenICam_v2_3/bin/Linux_armv7-a
#arm-frc-linux-gnueabi-g++ "-LC:\\Users\\R2D2/wpilib/cpp/current/lib" -Wl,-rpath,/opt/GenICam_v2_3/bin/Linux_armv7-a -o FRCUserProgram "src\\Subsystems\\ExampleSubsystem.o" "src\\Robot.o" "src\\OI.o" "src\\Commands\\ExampleCommand.o" "src\\CommandBase.o" -lwpi 

OUTPUT_OPTION = -o $@

build: mkdir-$(OBJDIR) mkdir-$(BINDIR) $(addprefix $(OBJDIR)/, $(OBJS))
	$(CXX) $(addprefix $(OBJDIR)/, $(OBJS)) $(LDFLAGS) -o $(BINDIR)/$(OUT) -lwpi

dist/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $< $(OUTPUT_OPTION)

# create the OBJDIR if it does not exist
# $(OBJDIR):
# 	mkdir -p $(OBJDIR)

# src/%.o: src/%.cpp
# 	$(CXX) $(OUTPUT_OPTION) $<

mkdir-%:
	mkdir -p $(@:mkdir-%=%)
dist/%:
	@echo $@

test:
	@echo $(OBJS)


.PHONY: clean build
clean:
	$(RM) -rf $(OBJDIR) $(BINDIR)
