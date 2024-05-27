##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=DebuggingAndCompiler
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/mugiw/Documents/Workspaces/Workspace2
ProjectPath            :=C:/Users/mugiw/Documents/Workspaces/Workspace2/DebuggingAndCompiler
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/DebuggingAndCompiler
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
CFLAGS   :=  -O0 -gdwarf-2 -std=c99 -Wall -D DEBON_C -D FIX2 $(Preprocessors)
ASFLAGS  := 
AS       := C:/cygwin64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/classChallenge.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/coreProfilingStatic.c$(ObjectSuffix) $(IntermediateDirectory)/debugGdb.c$(ObjectSuffix) $(IntermediateDirectory)/debugPre.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/classChallenge.c$(ObjectSuffix): classChallenge.c $(IntermediateDirectory)/classChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/DebuggingAndCompiler/classChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/classChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/classChallenge.c$(DependSuffix): classChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/classChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/classChallenge.c$(DependSuffix) -MM classChallenge.c

$(IntermediateDirectory)/classChallenge.c$(PreprocessSuffix): classChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/classChallenge.c$(PreprocessSuffix) classChallenge.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/DebuggingAndCompiler/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/coreProfilingStatic.c$(ObjectSuffix): coreProfilingStatic.c $(IntermediateDirectory)/coreProfilingStatic.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/DebuggingAndCompiler/coreProfilingStatic.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/coreProfilingStatic.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/coreProfilingStatic.c$(DependSuffix): coreProfilingStatic.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/coreProfilingStatic.c$(ObjectSuffix) -MF$(IntermediateDirectory)/coreProfilingStatic.c$(DependSuffix) -MM coreProfilingStatic.c

$(IntermediateDirectory)/coreProfilingStatic.c$(PreprocessSuffix): coreProfilingStatic.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/coreProfilingStatic.c$(PreprocessSuffix) coreProfilingStatic.c

$(IntermediateDirectory)/debugGdb.c$(ObjectSuffix): debugGdb.c $(IntermediateDirectory)/debugGdb.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/DebuggingAndCompiler/debugGdb.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/debugGdb.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/debugGdb.c$(DependSuffix): debugGdb.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/debugGdb.c$(ObjectSuffix) -MF$(IntermediateDirectory)/debugGdb.c$(DependSuffix) -MM debugGdb.c

$(IntermediateDirectory)/debugGdb.c$(PreprocessSuffix): debugGdb.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/debugGdb.c$(PreprocessSuffix) debugGdb.c

$(IntermediateDirectory)/debugPre.c$(ObjectSuffix): debugPre.c $(IntermediateDirectory)/debugPre.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/DebuggingAndCompiler/debugPre.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/debugPre.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/debugPre.c$(DependSuffix): debugPre.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/debugPre.c$(ObjectSuffix) -MF$(IntermediateDirectory)/debugPre.c$(DependSuffix) -MM debugPre.c

$(IntermediateDirectory)/debugPre.c$(PreprocessSuffix): debugPre.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/debugPre.c$(PreprocessSuffix) debugPre.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


