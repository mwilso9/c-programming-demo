##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=InputOutput
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/mugiw/Documents/Workspaces/Workspace2
ProjectPath            :=C:/Users/mugiw/Documents/Workspaces/Workspace2/InputOutput
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/InputOutput
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
Objects0=$(IntermediateDirectory)/char.c$(ObjectSuffix) $(IntermediateDirectory)/charChallenge.c$(ObjectSuffix) $(IntermediateDirectory)/formattingChallenge.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/formatting.c$(ObjectSuffix) $(IntermediateDirectory)/stringLecture.c$(ObjectSuffix) $(IntermediateDirectory)/stringChallenge.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/char.c$(ObjectSuffix): char.c $(IntermediateDirectory)/char.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/InputOutput/char.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/char.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/char.c$(DependSuffix): char.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/char.c$(ObjectSuffix) -MF$(IntermediateDirectory)/char.c$(DependSuffix) -MM char.c

$(IntermediateDirectory)/char.c$(PreprocessSuffix): char.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/char.c$(PreprocessSuffix) char.c

$(IntermediateDirectory)/charChallenge.c$(ObjectSuffix): charChallenge.c $(IntermediateDirectory)/charChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/InputOutput/charChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/charChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/charChallenge.c$(DependSuffix): charChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/charChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/charChallenge.c$(DependSuffix) -MM charChallenge.c

$(IntermediateDirectory)/charChallenge.c$(PreprocessSuffix): charChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/charChallenge.c$(PreprocessSuffix) charChallenge.c

$(IntermediateDirectory)/formattingChallenge.c$(ObjectSuffix): formattingChallenge.c $(IntermediateDirectory)/formattingChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/InputOutput/formattingChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/formattingChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/formattingChallenge.c$(DependSuffix): formattingChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/formattingChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/formattingChallenge.c$(DependSuffix) -MM formattingChallenge.c

$(IntermediateDirectory)/formattingChallenge.c$(PreprocessSuffix): formattingChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/formattingChallenge.c$(PreprocessSuffix) formattingChallenge.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/InputOutput/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/formatting.c$(ObjectSuffix): formatting.c $(IntermediateDirectory)/formatting.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/InputOutput/formatting.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/formatting.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/formatting.c$(DependSuffix): formatting.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/formatting.c$(ObjectSuffix) -MF$(IntermediateDirectory)/formatting.c$(DependSuffix) -MM formatting.c

$(IntermediateDirectory)/formatting.c$(PreprocessSuffix): formatting.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/formatting.c$(PreprocessSuffix) formatting.c

$(IntermediateDirectory)/stringLecture.c$(ObjectSuffix): stringLecture.c $(IntermediateDirectory)/stringLecture.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/InputOutput/stringLecture.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stringLecture.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stringLecture.c$(DependSuffix): stringLecture.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stringLecture.c$(ObjectSuffix) -MF$(IntermediateDirectory)/stringLecture.c$(DependSuffix) -MM stringLecture.c

$(IntermediateDirectory)/stringLecture.c$(PreprocessSuffix): stringLecture.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stringLecture.c$(PreprocessSuffix) stringLecture.c

$(IntermediateDirectory)/stringChallenge.c$(ObjectSuffix): stringChallenge.c $(IntermediateDirectory)/stringChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/InputOutput/stringChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stringChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stringChallenge.c$(DependSuffix): stringChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stringChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/stringChallenge.c$(DependSuffix) -MM stringChallenge.c

$(IntermediateDirectory)/stringChallenge.c$(PreprocessSuffix): stringChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stringChallenge.c$(PreprocessSuffix) stringChallenge.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


