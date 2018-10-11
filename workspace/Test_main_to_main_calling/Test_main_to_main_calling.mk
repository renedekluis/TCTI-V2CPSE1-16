##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Test_main_to_main_calling
ConfigurationName      :=Debug
WorkspacePath          :=D:/Documents_D/HBO-ICT/git/HBO-ICT/Jaar4/C_Herkansing/TCTI-V2CPSE1-16/workspace
ProjectPath            :=D:/Documents_D/HBO-ICT/git/HBO-ICT/Jaar4/C_Herkansing/TCTI-V2CPSE1-16/workspace/Test_main_to_main_calling
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Rene
Date                   :=11/10/2018
CodeLitePath           :="D:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-32/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-32/bin/g++.exe -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Test_main_to_main_calling.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  -lgdi32 -static-libgcc -static-libstdc++ 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../Catch/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-32/bin/ar.exe rcu
CXX      := C:/TDM-GCC-32/bin/g++.exe
CC       := C:/TDM-GCC-32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/app_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/secondMain.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Documents_D/HBO-ICT/git/HBO-ICT/Jaar4/C_Herkansing/TCTI-V2CPSE1-16/workspace/Test_main_to_main_calling/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/app_main.cpp$(ObjectSuffix): app_main.cpp $(IntermediateDirectory)/app_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Documents_D/HBO-ICT/git/HBO-ICT/Jaar4/C_Herkansing/TCTI-V2CPSE1-16/workspace/Test_main_to_main_calling/app_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/app_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/app_main.cpp$(DependSuffix): app_main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/app_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/app_main.cpp$(DependSuffix) -MM app_main.cpp

$(IntermediateDirectory)/app_main.cpp$(PreprocessSuffix): app_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/app_main.cpp$(PreprocessSuffix) app_main.cpp

$(IntermediateDirectory)/secondMain.cpp$(ObjectSuffix): secondMain.cpp $(IntermediateDirectory)/secondMain.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Documents_D/HBO-ICT/git/HBO-ICT/Jaar4/C_Herkansing/TCTI-V2CPSE1-16/workspace/Test_main_to_main_calling/secondMain.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/secondMain.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/secondMain.cpp$(DependSuffix): secondMain.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/secondMain.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/secondMain.cpp$(DependSuffix) -MM secondMain.cpp

$(IntermediateDirectory)/secondMain.cpp$(PreprocessSuffix): secondMain.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/secondMain.cpp$(PreprocessSuffix) secondMain.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


