##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=DataStructures
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/mugiw/Documents/Workspaces/Workspace2
ProjectPath            :=C:/Users/mugiw/Documents/Workspaces/Workspace2/DataStructures
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/DataStructures
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
Objects0=$(IntermediateDirectory)/linkedLists.c$(ObjectSuffix) $(IntermediateDirectory)/binaryTrees.c$(ObjectSuffix) $(IntermediateDirectory)/queues.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/stacks.c$(ObjectSuffix) $(IntermediateDirectory)/linkedListsChall.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/linkedLists.c$(ObjectSuffix): linkedLists.c $(IntermediateDirectory)/linkedLists.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/DataStructures/linkedLists.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/linkedLists.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/linkedLists.c$(DependSuffix): linkedLists.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/linkedLists.c$(ObjectSuffix) -MF$(IntermediateDirectory)/linkedLists.c$(DependSuffix) -MM linkedLists.c

$(IntermediateDirectory)/linkedLists.c$(PreprocessSuffix): linkedLists.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/linkedLists.c$(PreprocessSuffix) linkedLists.c

$(IntermediateDirectory)/binaryTrees.c$(ObjectSuffix): binaryTrees.c $(IntermediateDirectory)/binaryTrees.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/DataStructures/binaryTrees.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/binaryTrees.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/binaryTrees.c$(DependSuffix): binaryTrees.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/binaryTrees.c$(ObjectSuffix) -MF$(IntermediateDirectory)/binaryTrees.c$(DependSuffix) -MM binaryTrees.c

$(IntermediateDirectory)/binaryTrees.c$(PreprocessSuffix): binaryTrees.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/binaryTrees.c$(PreprocessSuffix) binaryTrees.c

$(IntermediateDirectory)/queues.c$(ObjectSuffix): queues.c $(IntermediateDirectory)/queues.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/DataStructures/queues.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/queues.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/queues.c$(DependSuffix): queues.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/queues.c$(ObjectSuffix) -MF$(IntermediateDirectory)/queues.c$(DependSuffix) -MM queues.c

$(IntermediateDirectory)/queues.c$(PreprocessSuffix): queues.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/queues.c$(PreprocessSuffix) queues.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/DataStructures/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/stacks.c$(ObjectSuffix): stacks.c $(IntermediateDirectory)/stacks.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/DataStructures/stacks.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stacks.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stacks.c$(DependSuffix): stacks.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stacks.c$(ObjectSuffix) -MF$(IntermediateDirectory)/stacks.c$(DependSuffix) -MM stacks.c

$(IntermediateDirectory)/stacks.c$(PreprocessSuffix): stacks.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stacks.c$(PreprocessSuffix) stacks.c

$(IntermediateDirectory)/linkedListsChall.c$(ObjectSuffix): linkedListsChall.c $(IntermediateDirectory)/linkedListsChall.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/DataStructures/linkedListsChall.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/linkedListsChall.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/linkedListsChall.c$(DependSuffix): linkedListsChall.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/linkedListsChall.c$(ObjectSuffix) -MF$(IntermediateDirectory)/linkedListsChall.c$(DependSuffix) -MM linkedListsChall.c

$(IntermediateDirectory)/linkedListsChall.c$(PreprocessSuffix): linkedListsChall.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/linkedListsChall.c$(PreprocessSuffix) linkedListsChall.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


