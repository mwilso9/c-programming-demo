##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ControlFLow
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/mugiw/Documents/Workspaces/Workspace2
ProjectPath            :=C:/Users/mugiw/Documents/Workspaces/Workspace2/ControlFLow
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/ControlFLow
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=mugiw
Date                   :=27/05/2024
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir -p
LinkerName             :=C:/cygwin64/bin/gcc.exe
SharedObjectLinkerName :=C:/cygwin64/bin/gcc.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Users/mugiw/Documents/Workspaces/Workspace2/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -static
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/cygwin64/bin/ar.exe rcu
CXX      := C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe
CC       := C:/cygwin64/bin/gcc.exe
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -O0 -gdwarf-2 -std=c99 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/cygwin64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/gotoChallenge.c$(ObjectSuffix) $(IntermediateDirectory)/goto.c$(ObjectSuffix) $(IntermediateDirectory)/jump.c$(ObjectSuffix) $(IntermediateDirectory)/nullComma.c$(ObjectSuffix) $(IntermediateDirectory)/jumpChallenge.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/ControlFLow/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/gotoChallenge.c$(ObjectSuffix): gotoChallenge.c $(IntermediateDirectory)/gotoChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/ControlFLow/gotoChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gotoChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gotoChallenge.c$(DependSuffix): gotoChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gotoChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/gotoChallenge.c$(DependSuffix) -MM gotoChallenge.c

$(IntermediateDirectory)/gotoChallenge.c$(PreprocessSuffix): gotoChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gotoChallenge.c$(PreprocessSuffix) gotoChallenge.c

$(IntermediateDirectory)/goto.c$(ObjectSuffix): goto.c $(IntermediateDirectory)/goto.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/ControlFLow/goto.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/goto.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/goto.c$(DependSuffix): goto.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/goto.c$(ObjectSuffix) -MF$(IntermediateDirectory)/goto.c$(DependSuffix) -MM goto.c

$(IntermediateDirectory)/goto.c$(PreprocessSuffix): goto.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/goto.c$(PreprocessSuffix) goto.c

$(IntermediateDirectory)/jump.c$(ObjectSuffix): jump.c $(IntermediateDirectory)/jump.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/ControlFLow/jump.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/jump.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/jump.c$(DependSuffix): jump.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/jump.c$(ObjectSuffix) -MF$(IntermediateDirectory)/jump.c$(DependSuffix) -MM jump.c

$(IntermediateDirectory)/jump.c$(PreprocessSuffix): jump.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/jump.c$(PreprocessSuffix) jump.c

$(IntermediateDirectory)/nullComma.c$(ObjectSuffix): nullComma.c $(IntermediateDirectory)/nullComma.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/ControlFLow/nullComma.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nullComma.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nullComma.c$(DependSuffix): nullComma.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nullComma.c$(ObjectSuffix) -MF$(IntermediateDirectory)/nullComma.c$(DependSuffix) -MM nullComma.c

$(IntermediateDirectory)/nullComma.c$(PreprocessSuffix): nullComma.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nullComma.c$(PreprocessSuffix) nullComma.c

$(IntermediateDirectory)/jumpChallenge.c$(ObjectSuffix): jumpChallenge.c $(IntermediateDirectory)/jumpChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/ControlFLow/jumpChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/jumpChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/jumpChallenge.c$(DependSuffix): jumpChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/jumpChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/jumpChallenge.c$(DependSuffix) -MM jumpChallenge.c

$(IntermediateDirectory)/jumpChallenge.c$(PreprocessSuffix): jumpChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/jumpChallenge.c$(PreprocessSuffix) jumpChallenge.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


