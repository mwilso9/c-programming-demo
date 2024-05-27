##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Binary
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/mugiw/Documents/Workspaces/Workspace2
ProjectPath            :=C:/Users/mugiw/Documents/Workspaces/Workspace2/Binary
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Binary
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
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/bitmaskChallenge.c$(ObjectSuffix) $(IntermediateDirectory)/bitwiseOperators.c$(ObjectSuffix) $(IntermediateDirectory)/bitFieldChallenge.c$(ObjectSuffix) $(IntermediateDirectory)/bitwiseOperatorsChallenge.c$(ObjectSuffix) $(IntermediateDirectory)/binaryNumberChallenge.c$(ObjectSuffix) $(IntermediateDirectory)/bitmask.c$(ObjectSuffix) $(IntermediateDirectory)/bitField.c$(ObjectSuffix) 



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
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Binary/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/bitmaskChallenge.c$(ObjectSuffix): bitmaskChallenge.c $(IntermediateDirectory)/bitmaskChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Binary/bitmaskChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bitmaskChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bitmaskChallenge.c$(DependSuffix): bitmaskChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bitmaskChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/bitmaskChallenge.c$(DependSuffix) -MM bitmaskChallenge.c

$(IntermediateDirectory)/bitmaskChallenge.c$(PreprocessSuffix): bitmaskChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bitmaskChallenge.c$(PreprocessSuffix) bitmaskChallenge.c

$(IntermediateDirectory)/bitwiseOperators.c$(ObjectSuffix): bitwiseOperators.c $(IntermediateDirectory)/bitwiseOperators.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Binary/bitwiseOperators.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bitwiseOperators.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bitwiseOperators.c$(DependSuffix): bitwiseOperators.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bitwiseOperators.c$(ObjectSuffix) -MF$(IntermediateDirectory)/bitwiseOperators.c$(DependSuffix) -MM bitwiseOperators.c

$(IntermediateDirectory)/bitwiseOperators.c$(PreprocessSuffix): bitwiseOperators.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bitwiseOperators.c$(PreprocessSuffix) bitwiseOperators.c

$(IntermediateDirectory)/bitFieldChallenge.c$(ObjectSuffix): bitFieldChallenge.c $(IntermediateDirectory)/bitFieldChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Binary/bitFieldChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bitFieldChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bitFieldChallenge.c$(DependSuffix): bitFieldChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bitFieldChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/bitFieldChallenge.c$(DependSuffix) -MM bitFieldChallenge.c

$(IntermediateDirectory)/bitFieldChallenge.c$(PreprocessSuffix): bitFieldChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bitFieldChallenge.c$(PreprocessSuffix) bitFieldChallenge.c

$(IntermediateDirectory)/bitwiseOperatorsChallenge.c$(ObjectSuffix): bitwiseOperatorsChallenge.c $(IntermediateDirectory)/bitwiseOperatorsChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Binary/bitwiseOperatorsChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bitwiseOperatorsChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bitwiseOperatorsChallenge.c$(DependSuffix): bitwiseOperatorsChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bitwiseOperatorsChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/bitwiseOperatorsChallenge.c$(DependSuffix) -MM bitwiseOperatorsChallenge.c

$(IntermediateDirectory)/bitwiseOperatorsChallenge.c$(PreprocessSuffix): bitwiseOperatorsChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bitwiseOperatorsChallenge.c$(PreprocessSuffix) bitwiseOperatorsChallenge.c

$(IntermediateDirectory)/binaryNumberChallenge.c$(ObjectSuffix): binaryNumberChallenge.c $(IntermediateDirectory)/binaryNumberChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Binary/binaryNumberChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/binaryNumberChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/binaryNumberChallenge.c$(DependSuffix): binaryNumberChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/binaryNumberChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/binaryNumberChallenge.c$(DependSuffix) -MM binaryNumberChallenge.c

$(IntermediateDirectory)/binaryNumberChallenge.c$(PreprocessSuffix): binaryNumberChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/binaryNumberChallenge.c$(PreprocessSuffix) binaryNumberChallenge.c

$(IntermediateDirectory)/bitmask.c$(ObjectSuffix): bitmask.c $(IntermediateDirectory)/bitmask.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Binary/bitmask.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bitmask.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bitmask.c$(DependSuffix): bitmask.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bitmask.c$(ObjectSuffix) -MF$(IntermediateDirectory)/bitmask.c$(DependSuffix) -MM bitmask.c

$(IntermediateDirectory)/bitmask.c$(PreprocessSuffix): bitmask.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bitmask.c$(PreprocessSuffix) bitmask.c

$(IntermediateDirectory)/bitField.c$(ObjectSuffix): bitField.c $(IntermediateDirectory)/bitField.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Binary/bitField.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bitField.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bitField.c$(DependSuffix): bitField.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bitField.c$(ObjectSuffix) -MF$(IntermediateDirectory)/bitField.c$(DependSuffix) -MM bitField.c

$(IntermediateDirectory)/bitField.c$(PreprocessSuffix): bitField.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bitField.c$(PreprocessSuffix) bitField.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


