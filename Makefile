
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


OBJS = $(SRCS:src/%.cpp=%.o)

TARGET = FRCUserProgram
CPPFLAGS = -std=c++1y -I"$(WPILIB)/cpp/current/include" -I"$(SRCDIR)" -O0 -g3 -Wall -c -fmessage-length=0
LDFLAGS = -L$(WPILIB)/cpp/current/lib -Wl,-rpath,/opt/GenICam_v2_3/bin/Linux_armv7-a

OUTPUT_OPTION = -o $@

build: mkdir-$(OBJDIR) mkdir-$(BINDIR) $(addprefix $(OBJDIR)/, $(OBJS))
	@echo Linking
	@$(CXX) $(addprefix $(OBJDIR)/, $(OBJS)) $(LDFLAGS) -o $(BINDIR)/$(OUT) -lwpi


dist/%.o: src/%.cpp
	@echo Compiling $(notdir $@)
	@mkdir -p $(dir $@)
	@$(CXX) -c $(CFLAGS) $(CPPFLAGS) $< $(OUTPUT_OPTION)

mkdir-%:
	@mkdir -p $(@:mkdir-%=%)


.PHONY: clean build
clean:
	$(RM) -rf $(OBJDIR) $(BINDIR)
