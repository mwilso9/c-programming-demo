##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Testing
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/mugiw/Documents/Workspaces/Workspace2
ProjectPath            :=C:/Users/mugiw/Documents/Workspaces/Workspace2/Testing
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Testing
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
Objects0=$(IntermediateDirectory)/other.c$(ObjectSuffix) $(IntermediateDirectory)/linkedlist.c$(ObjectSuffix) $(IntermediateDirectory)/insert.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/other.c$(ObjectSuffix): other.c $(IntermediateDirectory)/other.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Testing/other.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/other.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/other.c$(DependSuffix): other.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/other.c$(ObjectSuffix) -MF$(IntermediateDirectory)/other.c$(DependSuffix) -MM other.c

$(IntermediateDirectory)/other.c$(PreprocessSuffix): other.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/other.c$(PreprocessSuffix) other.c

$(IntermediateDirectory)/linkedlist.c$(ObjectSuffix): linkedlist.c $(IntermediateDirectory)/linkedlist.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Testing/linkedlist.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/linkedlist.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/linkedlist.c$(DependSuffix): linkedlist.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/linkedlist.c$(ObjectSuffix) -MF$(IntermediateDirectory)/linkedlist.c$(DependSuffix) -MM linkedlist.c

$(IntermediateDirectory)/linkedlist.c$(PreprocessSuffix): linkedlist.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/linkedlist.c$(PreprocessSuffix) linkedlist.c

$(IntermediateDirectory)/insert.c$(ObjectSuffix): insert.c $(IntermediateDirectory)/insert.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Testing/insert.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/insert.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/insert.c$(DependSuffix): insert.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/insert.c$(ObjectSuffix) -MF$(IntermediateDirectory)/insert.c$(DependSuffix) -MM insert.c

$(IntermediateDirectory)/insert.c$(PreprocessSuffix): insert.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/insert.c$(PreprocessSuffix) insert.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/Testing/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


