##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Threads
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/mugiw/Documents/Workspaces/Workspace2
ProjectPath            :=C:/Users/mugiw/Documents/Workspaces/Workspace2/Threads
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Threads
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
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/threadsIntro.c$(ObjectSuffix) $(IntermediateDirectory)/mutexes.c$(ObjectSuffix) $(IntermediateDirectory)/threadFunc.c$(ObjectSuffix) $(IntermediateDirectory)/conditionVariables.c$(ObjectSuffix) $(IntermediateDirectory)/threadChallenge.c$(ObjectSuffix) 



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
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Threads/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/threadsIntro.c$(ObjectSuffix): threadsIntro.c $(IntermediateDirectory)/threadsIntro.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Threads/threadsIntro.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/threadsIntro.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/threadsIntro.c$(DependSuffix): threadsIntro.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/threadsIntro.c$(ObjectSuffix) -MF$(IntermediateDirectory)/threadsIntro.c$(DependSuffix) -MM threadsIntro.c

$(IntermediateDirectory)/threadsIntro.c$(PreprocessSuffix): threadsIntro.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/threadsIntro.c$(PreprocessSuffix) threadsIntro.c

$(IntermediateDirectory)/mutexes.c$(ObjectSuffix): mutexes.c $(IntermediateDirectory)/mutexes.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Threads/mutexes.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mutexes.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mutexes.c$(DependSuffix): mutexes.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mutexes.c$(ObjectSuffix) -MF$(IntermediateDirectory)/mutexes.c$(DependSuffix) -MM mutexes.c

$(IntermediateDirectory)/mutexes.c$(PreprocessSuffix): mutexes.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mutexes.c$(PreprocessSuffix) mutexes.c

$(IntermediateDirectory)/threadFunc.c$(ObjectSuffix): threadFunc.c $(IntermediateDirectory)/threadFunc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Threads/threadFunc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/threadFunc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/threadFunc.c$(DependSuffix): threadFunc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/threadFunc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/threadFunc.c$(DependSuffix) -MM threadFunc.c

$(IntermediateDirectory)/threadFunc.c$(PreprocessSuffix): threadFunc.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/threadFunc.c$(PreprocessSuffix) threadFunc.c

$(IntermediateDirectory)/conditionVariables.c$(ObjectSuffix): conditionVariables.c $(IntermediateDirectory)/conditionVariables.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Threads/conditionVariables.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/conditionVariables.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/conditionVariables.c$(DependSuffix): conditionVariables.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/conditionVariables.c$(ObjectSuffix) -MF$(IntermediateDirectory)/conditionVariables.c$(DependSuffix) -MM conditionVariables.c

$(IntermediateDirectory)/conditionVariables.c$(PreprocessSuffix): conditionVariables.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/conditionVariables.c$(PreprocessSuffix) conditionVariables.c

$(IntermediateDirectory)/threadChallenge.c$(ObjectSuffix): threadChallenge.c $(IntermediateDirectory)/threadChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Threads/threadChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/threadChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/threadChallenge.c$(DependSuffix): threadChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/threadChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/threadChallenge.c$(DependSuffix) -MM threadChallenge.c

$(IntermediateDirectory)/threadChallenge.c$(PreprocessSuffix): threadChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/threadChallenge.c$(PreprocessSuffix) threadChallenge.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


