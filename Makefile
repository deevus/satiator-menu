# Jo Engine Flags

JO_COMPILE_WITH_VIDEO_MODULE = 0
JO_COMPILE_WITH_BACKUP_MODULE = 0
JO_COMPILE_WITH_TGA_MODULE = 1
JO_COMPILE_WITH_AUDIO_MODULE = 0
JO_COMPILE_WITH_3D_MODULE = 0
JO_COMPILE_WITH_PSEUDO_MODE7_MODULE = 0
JO_COMPILE_WITH_EFFECTS_MODULE = 0
JO_COMPILE_WITH_STORYBOARD_MODULE = 1
JO_DEBUG = 1

# Directories

LIB_DIR=./lib
ASSETS_DIR=./assets
JO_ENGINE_SRC_DIR=$(LIB_DIR)/joengine/jo_engine
COMPILER_DIR=$(LIB_DIR)/joengine/Compiler
SH_COFF_BIN=$(COMPILER_DIR)/SH_COFF/sh-coff/bin
OUT_DIR=./build

# Executables

ifeq ($(OS), Windows_NT)
	CC=$(SH_COFF_BIN)/sh-coff-gcc.exe
	CONV=$(SH_COFF_BIN)/sh-coff-objcopy.exe
	CUE_MAKER=$(COMPILER_DIR)/TOOLS/JoEngineCueMaker.exe
else
	SH_COFF_BIN=$(COMPILER_DIR)/SH_NONE_ELF/bin
	CC=$(SH_COFF_BIN)/sh-none-elf-gcc-8.2.0
	CONV=$(SH_COFF_BIN)/sh-none-elf-objcopy
	CUE_MAKER=$(COMPILER_DIR)/TOOLS/CueMaker
endif

MKISOFS=mkisofs
RM=rm -rf
MKDIR=mkdir -p

# Sources

SRCS=src/main.c

CCFLAGS += -flto

ifeq (${JO_FRAMERATE},)
	CCFLAGS += -DJO_FRAMERATE=1
else
	CCFLAGS += -DJO_FRAMERATE=${JO_FRAMERATE}
endif

ifeq (${JO_COMPILE_USING_SGL},)
	JO_COMPILE_USING_SGL = 1
endif

ifeq (${JO_COMPILE_WITH_FS_MODULE},)
	JO_COMPILE_WITH_FS_MODULE = 1
endif

ifeq (1,${JO_PSEUDO_SATURN_KAI_SUPPORT})
	JO_COMPILE_WITH_RAM_CARD_MODULE = 0
endif

ifeq (1,${JO_COMPILE_USING_SGL})
	CCFLAGS += -DJO_COMPILE_USING_SGL
endif

ifeq (1,${JO_COMPILE_WITH_VIDEO_MODULE})
	ifeq (1,${JO_COMPILE_USING_SGL})
		LIBS += $(SGLLDR)/libcpk.a $(SGLLDR)/LIBSND.a
	endif

	CCFLAGS += -DJO_COMPILE_WITH_VIDEO_SUPPORT
	SRCS += $(JO_ENGINE_SRC_DIR)/video.c
endif

ifeq (1,${JO_COMPILE_WITH_BACKUP_MODULE})
	CCFLAGS += -DJO_COMPILE_WITH_BACKUP_SUPPORT
	SRCS += $(JO_ENGINE_SRC_DIR)/backup.c
endif

ifeq (1,${JO_COMPILE_WITH_TGA_MODULE})
	CCFLAGS += -DJO_COMPILE_WITH_TGA_SUPPORT
	SRCS += $(JO_ENGINE_SRC_DIR)/tga.c
endif

ifeq (1,${JO_COMPILE_WITH_AUDIO_MODULE})
	CCFLAGS += -DJO_COMPILE_WITH_AUDIO_SUPPORT
	SRCS += $(JO_ENGINE_SRC_DIR)/audio.c
endif

ifeq (1,${JO_COMPILE_WITH_3D_MODULE})
	CCFLAGS += -DJO_COMPILE_WITH_3D_SUPPORT
	SRCS += $(JO_ENGINE_SRC_DIR)/3d.c
endif

ifeq (1,${JO_COMPILE_WITH_FS_MODULE})
	CCFLAGS += -DJO_COMPILE_WITH_FS_SUPPORT
	SRCS += $(JO_ENGINE_SRC_DIR)/fs.c
endif

ifeq (1,${JO_COMPILE_WITH_STORYBOARD_MODULE})
	CCFLAGS += -DJO_COMPILE_WITH_STORYBOARD_SUPPORT
	SRCS += $(JO_ENGINE_SRC_DIR)/storyboard.c
endif

ifeq (1,${JO_COMPILE_WITH_PSEUDO_MODE7_MODULE})
	CCFLAGS += -DJO_COMPILE_WITH_PSEUDO_MODE7_SUPPORT
	SRCS += $(JO_ENGINE_SRC_DIR)/mode7.c
endif

ifeq (1,${JO_COMPILE_WITH_EFFECTS_MODULE})
	CCFLAGS += -DJO_COMPILE_WITH_EFFECTS_SUPPORT
	SRCS += $(JO_ENGINE_SRC_DIR)/effects.c
endif

ifeq (${JO_GLOBAL_MEMORY_SIZE_FOR_MALLOC},)
	ifeq (1,${JO_COMPILE_WITH_VIDEO_MODULE})
		CCFLAGS += -DJO_GLOBAL_MEMORY_SIZE_FOR_MALLOC=393216
	else
		CCFLAGS += -DJO_GLOBAL_MEMORY_SIZE_FOR_MALLOC=524288
	endif
else
	CCFLAGS += -DJO_GLOBAL_MEMORY_SIZE_FOR_MALLOC=${JO_GLOBAL_MEMORY_SIZE_FOR_MALLOC}
endif

ifeq (${JO_MAX_SPRITE},)
	CCFLAGS += -DJO_MAX_SPRITE=255
else
	CCFLAGS += -DJO_MAX_SPRITE=${JO_MAX_SPRITE}
endif

ifeq (${JO_MAX_FILE_IN_IMAGE_PACK},)
	CCFLAGS += -DJO_MAX_FILE_IN_IMAGE_PACK=32
else
	CCFLAGS += -DJO_MAX_FILE_IN_IMAGE_PACK=${JO_MAX_FILE_IN_IMAGE_PACK}
endif

ifeq (${JO_MAP_MAX_LAYER},)
	CCFLAGS += -DJO_MAP_MAX_LAYER=8
else
	CCFLAGS += -DJO_MAP_MAX_LAYER=${JO_MAP_MAX_LAYER}
endif

ifeq (${JO_MAX_SPRITE_ANIM},)
	CCFLAGS += -DJO_MAX_SPRITE_ANIM=16
else
	CCFLAGS += -DJO_MAX_SPRITE_ANIM=${JO_MAX_SPRITE_ANIM}
endif

ifeq (${JO_MAX_FS_BACKGROUND_JOBS},)
	CCFLAGS += -DJO_MAX_FS_BACKGROUND_JOBS=4
else
	CCFLAGS += -DJO_MAX_FS_BACKGROUND_JOBS=${JO_MAX_FS_BACKGROUND_JOBS}
endif

ifeq (${JO_DEBUG},)
	CCFLAGS += -DJO_DEBUG
else
	ifeq (1,${JO_DEBUG})
		CCFLAGS += -DJO_DEBUG
	endif
endif

ifeq (${JO_480p},)
else
	CCFLAGS += -DJO_480p
endif

ifeq (${JO_NTSC},)
	CCFLAGS += -DJO_NTSC_VERSION
else
	ifeq (1,${JO_NTSC})
		CCFLAGS += -DJO_NTSC_VERSION
	else
		CCFLAGS += -DJO_PAL_VERSION
	endif
endif

ifeq (${JO_COMPILE_WITH_RAM_CARD_MODULE},)
	CCFLAGS += -DJO_COMPILE_WITH_RAM_CARD_SUPPORT
else
	ifeq (1,${JO_COMPILE_WITH_RAM_CARD_MODULE})
		CCFLAGS += -DJO_COMPILE_WITH_RAM_CARD_SUPPORT
	endif
endif

ifeq (${JO_COMPILE_WITH_DUAL_CPU_MODULE},)
	CCFLAGS += -DJO_COMPILE_WITH_DUAL_CPU_SUPPORT
else
	ifeq (1,${JO_COMPILE_WITH_DUAL_CPU_MODULE})
		CCFLAGS += -DJO_COMPILE_WITH_DUAL_CPU_SUPPORT
	endif
endif

SRCS += $(JO_ENGINE_SRC_DIR)/font.c $(JO_ENGINE_SRC_DIR)/input.c $(JO_ENGINE_SRC_DIR)/physics.c $(JO_ENGINE_SRC_DIR)/core.c \
		$(JO_ENGINE_SRC_DIR)/math.c $(JO_ENGINE_SRC_DIR)/malloc.c $(JO_ENGINE_SRC_DIR)/tools.c  \
		$(JO_ENGINE_SRC_DIR)/sprites.c $(JO_ENGINE_SRC_DIR)/map.c $(JO_ENGINE_SRC_DIR)/list.c $(JO_ENGINE_SRC_DIR)/sprite_animator.c \
		$(JO_ENGINE_SRC_DIR)/image.c $(JO_ENGINE_SRC_DIR)/background.c $(JO_ENGINE_SRC_DIR)/time.c $(JO_ENGINE_SRC_DIR)/vdp1_command_pipeline.c

SYSOBJS =

# remove the comment below when nosgl.linker is fixed
#ifeq (1,${JO_COMPILE_USING_SGL})
	SYSOBJS += $(SGLLDR)/SGLAREA.O
#endif

OBJS = $(SRCS:.c=.o)

# remove the comment below when nosgl.linker is fixed
#ifeq (1,${JO_COMPILE_USING_SGL})
	LIBS +=  $(SGLLDR)/SEGA_SYS.A $(SGLLDR)/LIBCD.A $(SGLLDR)/LIBSGL.A
#endif

# remove the comment below when nosgl.linker is fixed
#ifeq (1,${JO_COMPILE_USING_SGL})
	SGLDIR = $(COMPILER_DIR)/SGL_302j
	SGLIDR = $(SGLDIR)/INC
	SGLLDR = $(SGLDIR)/LIB_COFF
#endif

CMNDIR = $(COMPILER_DIR)/COMMON

CCFLAGS += -fkeep-inline-functions -W -Wall -Wshadow -Wbad-function-cast -Winline -Wcomment \
-Winline -Wlong-long -Wsign-compare -Wextra \
--param max-inline-insns-single=50 -fms-extensions -std=gnu99 \
-fmerge-all-constants -fno-ident -ffunction-sections -fdata-sections -fno-unwind-tables -fno-asynchronous-unwind-tables \
-fomit-frame-pointer -fstrength-reduce -frerun-loop-opt -Os -nodefaultlibs -nostdlib -fno-builtin -fno-pie \
-m2 -c -I$(JO_ENGINE_SRC_DIR)

# remove the comment below when nosgl.linker is fixed
#ifeq (1,${JO_COMPILE_USING_SGL})
	CCFLAGS += -I$(SGLIDR)
#endif

LDFLAGS = -m2
# remove the comment below when nosgl.linker is fixed
#ifeq (1,${JO_COMPILE_USING_SGL})
	LDFLAGS += -L$(SGLLDR)
#endif
LDFLAGS +=-Xlinker --format=coff-sh -Xlinker -T$(LDFILE) -Xlinker -Map \
          -Xlinker $(MPFILE) -Xlinker -e -Xlinker ___Start -nostartfiles
LIBS += -L./lib/joengine/Compiler/SH_COFF/sh-coff/sh-coff/lib/ -lc -Wl,--format=elf32-sh -lgcc
DFLAGS =

LIBS += -L.$(COMPILER_DIR)/SH_COFF/sh-coff/sh-coff/lib/ -Wl,--format=elf32-sh -Wl,--relax -lgcc

ENTRYPOINT = $(OUT_DIR)/0.bin
TARGET   = $(OUT_DIR)/satiator_menu.coff
TARGET1  = $(TARGET:.coff=.bin)
TARGET2  = $(TARGET:.coff=.iso)
TARGET3  = $(TARGET:.coff=.cue)
MPFILE   = $(TARGET:.coff=.map)
IPFILE   = $(CMNDIR)/IP.BIN
ifeq (1,${JO_COMPILE_USING_SGL})
	LDFILE   = $(CMNDIR)/sgl.linker
else
	LDFILE   = $(CMNDIR)/nosgl.linker
endif

MKISOFS_FLAGS=-quiet -sysid "SEGA SATURN" -volid "SaturnApp" -volset "SaturnApp" \
	-publisher "SEGA ENTERPRISES, LTD." -preparer "SEGA ENTERPRISES, LTD." -appid "SaturnApp" \
	-abstract "cd/ABS.TXT" -copyright "cd/CPY.TXT" -biblio "cd/BIB.TXT" -generic-boot $(IPFILE) \
	-full-iso9660-filenames -o $(TARGET2) $(ASSETS_DIR) $(ENTRYPOINT)

.phony: all

all: $(OUT_DIR) $(TARGET) $(TARGET1) $(TARGET2) $(TARGET3)

$(TARGET) : $(SYSOBJS) $(OBJS) $(MAKEFILE) $(LDFILE)
	$(CC) $(LDFLAGS) $(SYSOBJS) $(OBJS) $(LIBS) -o $@

$(TARGET1) : $(SYSOBJS) $(OBJS) $(MAKEFILE) $(LDFILE)
	$(CONV) -O binary $(TARGET) $(TARGET1)

$(TARGET2): $(TARGET)
	$(CONV) -O binary $(TARGET) $(ENTRYPOINT)
	$(MKISOFS) $(MKISOFS_FLAGS)

$(TARGET3): $(TARGET1) $(TARGET2)
	$(CUE_MAKER) $(OUT_DIR)

$(OUT_DIR):
	$(MKDIR) $(OUT_DIR)

.c.o:
	$(CC) $< $(DFLAGS) $(CCFLAGS) $(_CCFLAGS) -o $@

clean:
	$(RM) $(OBJS) $(OUT_DIR) $(MPFILE) $(ENTRYPOINT)

mednafen: all
	mednafen build/satiator_menu.cue
