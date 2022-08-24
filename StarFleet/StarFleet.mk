##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=StarFleet
ConfigurationName      :=Release
WorkspaceConfiguration :=Release
WorkspacePath          :=C:/Retrofit/CodeLite/Workspaces/StarFleet
ProjectPath            :=C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/StarFleet
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ayaskanta Ghosh
Date                   :=08/23/22
CodeLitePath           :="D:/Programs & Applications/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/Retrofit/MinGW64/v7.3.0/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/Retrofit/MinGW64/v7.3.0/mingw64/bin/g++.exe -shared -fPIC
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
OutputDirectory        :=C:/Retrofit/CodeLite/Workspaces/StarFleet/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=$(PreprocessorSwitch)NDEBUG $(PreprocessorSwitch)SFML_STATIC 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/Retrofit/MinGW64/v7.3.0/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)C:/Retrofit/CodeLite/Libraries/SFML-2.5.1/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-network $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-graphics" "sfml-window" "sfml-audio" "sfml-network" "sfml-system" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:/Retrofit/CodeLite/Libraries/SFML-2.5.1/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/Retrofit/MinGW64/v7.3.0/mingw64/bin/ar.exe rcu
CXX      := C:/Retrofit/MinGW64/v7.3.0/mingw64/bin/g++.exe
CC       := C:/Retrofit/MinGW64/v7.3.0/mingw64/bin/gcc.exe
CXXFLAGS :=  -O2 -Wall  -DSVN_REVISION=\"\"  $(Preprocessors)
CFLAGS   :=  -O2 -Wall  -DSVN_REVISION=\"\"  $(Preprocessors)
ASFLAGS  := 
AS       := C:/Retrofit/MinGW64/v7.3.0/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\Programs & Applications\CodeLite
WXWIN:=C:\Retrofit\CodeLite\Libraries\wxWidgets-3.1.5
WXCFG:=gcc_dll\mswu
PATH:=C:\Retrofit\MinGW64\v8.1.0\mingw64\bin;$PATH
Objects0=$(IntermediateDirectory)/Application.cpp$(ObjectSuffix) $(IntermediateDirectory)/Button.cpp$(ObjectSuffix) $(IntermediateDirectory)/Command.cpp$(ObjectSuffix) $(IntermediateDirectory)/CommandQueue.cpp$(ObjectSuffix) $(IntermediateDirectory)/Container.cpp$(ObjectSuffix) $(IntermediateDirectory)/DataTables.cpp$(ObjectSuffix) $(IntermediateDirectory)/Entity.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameLoadState.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameLoadTask.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameModeState.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/GameState.cpp$(ObjectSuffix) $(IntermediateDirectory)/TextNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/ResourceHolder.cpp$(ObjectSuffix) $(IntermediateDirectory)/MenuState.cpp$(ObjectSuffix) $(IntermediateDirectory)/TitleState.cpp$(ObjectSuffix) $(IntermediateDirectory)/Projectile.cpp$(ObjectSuffix) $(IntermediateDirectory)/World.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Label.cpp$(ObjectSuffix) $(IntermediateDirectory)/Player.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/GameOverState.cpp$(ObjectSuffix) $(IntermediateDirectory)/Spacecraft.cpp$(ObjectSuffix) $(IntermediateDirectory)/Component.cpp$(ObjectSuffix) $(IntermediateDirectory)/Utility.cpp$(ObjectSuffix) $(IntermediateDirectory)/TitleLoadTask.cpp$(ObjectSuffix) $(IntermediateDirectory)/TitleLoadState.cpp$(ObjectSuffix) $(IntermediateDirectory)/StringHelpers.cpp$(ObjectSuffix) $(IntermediateDirectory)/StateStack.cpp$(ObjectSuffix) $(IntermediateDirectory)/State.cpp$(ObjectSuffix) $(IntermediateDirectory)/SpriteNode.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/SettingsState.cpp$(ObjectSuffix) $(IntermediateDirectory)/SceneNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/Pickup.cpp$(ObjectSuffix) $(IntermediateDirectory)/PauseState.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Application.cpp$(ObjectSuffix): Application.cpp $(IntermediateDirectory)/Application.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/Application.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Application.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Application.cpp$(DependSuffix): Application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Application.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Application.cpp$(DependSuffix) -MM Application.cpp

$(IntermediateDirectory)/Application.cpp$(PreprocessSuffix): Application.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Application.cpp$(PreprocessSuffix) Application.cpp

$(IntermediateDirectory)/Button.cpp$(ObjectSuffix): Button.cpp $(IntermediateDirectory)/Button.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/Button.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Button.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Button.cpp$(DependSuffix): Button.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Button.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Button.cpp$(DependSuffix) -MM Button.cpp

$(IntermediateDirectory)/Button.cpp$(PreprocessSuffix): Button.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Button.cpp$(PreprocessSuffix) Button.cpp

$(IntermediateDirectory)/Command.cpp$(ObjectSuffix): Command.cpp $(IntermediateDirectory)/Command.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/Command.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Command.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Command.cpp$(DependSuffix): Command.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Command.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Command.cpp$(DependSuffix) -MM Command.cpp

$(IntermediateDirectory)/Command.cpp$(PreprocessSuffix): Command.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Command.cpp$(PreprocessSuffix) Command.cpp

$(IntermediateDirectory)/CommandQueue.cpp$(ObjectSuffix): CommandQueue.cpp $(IntermediateDirectory)/CommandQueue.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/CommandQueue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CommandQueue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CommandQueue.cpp$(DependSuffix): CommandQueue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CommandQueue.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CommandQueue.cpp$(DependSuffix) -MM CommandQueue.cpp

$(IntermediateDirectory)/CommandQueue.cpp$(PreprocessSuffix): CommandQueue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CommandQueue.cpp$(PreprocessSuffix) CommandQueue.cpp

$(IntermediateDirectory)/Container.cpp$(ObjectSuffix): Container.cpp $(IntermediateDirectory)/Container.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/Container.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Container.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Container.cpp$(DependSuffix): Container.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Container.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Container.cpp$(DependSuffix) -MM Container.cpp

$(IntermediateDirectory)/Container.cpp$(PreprocessSuffix): Container.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Container.cpp$(PreprocessSuffix) Container.cpp

$(IntermediateDirectory)/DataTables.cpp$(ObjectSuffix): DataTables.cpp $(IntermediateDirectory)/DataTables.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/DataTables.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DataTables.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DataTables.cpp$(DependSuffix): DataTables.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DataTables.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DataTables.cpp$(DependSuffix) -MM DataTables.cpp

$(IntermediateDirectory)/DataTables.cpp$(PreprocessSuffix): DataTables.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DataTables.cpp$(PreprocessSuffix) DataTables.cpp

$(IntermediateDirectory)/Entity.cpp$(ObjectSuffix): Entity.cpp $(IntermediateDirectory)/Entity.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/Entity.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Entity.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Entity.cpp$(DependSuffix): Entity.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Entity.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Entity.cpp$(DependSuffix) -MM Entity.cpp

$(IntermediateDirectory)/Entity.cpp$(PreprocessSuffix): Entity.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Entity.cpp$(PreprocessSuffix) Entity.cpp

$(IntermediateDirectory)/GameLoadState.cpp$(ObjectSuffix): GameLoadState.cpp $(IntermediateDirectory)/GameLoadState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/GameLoadState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameLoadState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameLoadState.cpp$(DependSuffix): GameLoadState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameLoadState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameLoadState.cpp$(DependSuffix) -MM GameLoadState.cpp

$(IntermediateDirectory)/GameLoadState.cpp$(PreprocessSuffix): GameLoadState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameLoadState.cpp$(PreprocessSuffix) GameLoadState.cpp

$(IntermediateDirectory)/GameLoadTask.cpp$(ObjectSuffix): GameLoadTask.cpp $(IntermediateDirectory)/GameLoadTask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/GameLoadTask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameLoadTask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameLoadTask.cpp$(DependSuffix): GameLoadTask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameLoadTask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameLoadTask.cpp$(DependSuffix) -MM GameLoadTask.cpp

$(IntermediateDirectory)/GameLoadTask.cpp$(PreprocessSuffix): GameLoadTask.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameLoadTask.cpp$(PreprocessSuffix) GameLoadTask.cpp

$(IntermediateDirectory)/GameModeState.cpp$(ObjectSuffix): GameModeState.cpp $(IntermediateDirectory)/GameModeState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/GameModeState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameModeState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameModeState.cpp$(DependSuffix): GameModeState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameModeState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameModeState.cpp$(DependSuffix) -MM GameModeState.cpp

$(IntermediateDirectory)/GameModeState.cpp$(PreprocessSuffix): GameModeState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameModeState.cpp$(PreprocessSuffix) GameModeState.cpp

$(IntermediateDirectory)/GameState.cpp$(ObjectSuffix): GameState.cpp $(IntermediateDirectory)/GameState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/GameState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameState.cpp$(DependSuffix): GameState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameState.cpp$(DependSuffix) -MM GameState.cpp

$(IntermediateDirectory)/GameState.cpp$(PreprocessSuffix): GameState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameState.cpp$(PreprocessSuffix) GameState.cpp

$(IntermediateDirectory)/TextNode.cpp$(ObjectSuffix): TextNode.cpp $(IntermediateDirectory)/TextNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/TextNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TextNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TextNode.cpp$(DependSuffix): TextNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TextNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TextNode.cpp$(DependSuffix) -MM TextNode.cpp

$(IntermediateDirectory)/TextNode.cpp$(PreprocessSuffix): TextNode.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TextNode.cpp$(PreprocessSuffix) TextNode.cpp

$(IntermediateDirectory)/ResourceHolder.cpp$(ObjectSuffix): ResourceHolder.cpp $(IntermediateDirectory)/ResourceHolder.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/ResourceHolder.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ResourceHolder.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ResourceHolder.cpp$(DependSuffix): ResourceHolder.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ResourceHolder.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ResourceHolder.cpp$(DependSuffix) -MM ResourceHolder.cpp

$(IntermediateDirectory)/ResourceHolder.cpp$(PreprocessSuffix): ResourceHolder.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ResourceHolder.cpp$(PreprocessSuffix) ResourceHolder.cpp

$(IntermediateDirectory)/MenuState.cpp$(ObjectSuffix): MenuState.cpp $(IntermediateDirectory)/MenuState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/MenuState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MenuState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MenuState.cpp$(DependSuffix): MenuState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MenuState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MenuState.cpp$(DependSuffix) -MM MenuState.cpp

$(IntermediateDirectory)/MenuState.cpp$(PreprocessSuffix): MenuState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MenuState.cpp$(PreprocessSuffix) MenuState.cpp

$(IntermediateDirectory)/TitleState.cpp$(ObjectSuffix): TitleState.cpp $(IntermediateDirectory)/TitleState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/TitleState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TitleState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TitleState.cpp$(DependSuffix): TitleState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TitleState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TitleState.cpp$(DependSuffix) -MM TitleState.cpp

$(IntermediateDirectory)/TitleState.cpp$(PreprocessSuffix): TitleState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TitleState.cpp$(PreprocessSuffix) TitleState.cpp

$(IntermediateDirectory)/Projectile.cpp$(ObjectSuffix): Projectile.cpp $(IntermediateDirectory)/Projectile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/Projectile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Projectile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Projectile.cpp$(DependSuffix): Projectile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Projectile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Projectile.cpp$(DependSuffix) -MM Projectile.cpp

$(IntermediateDirectory)/Projectile.cpp$(PreprocessSuffix): Projectile.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Projectile.cpp$(PreprocessSuffix) Projectile.cpp

$(IntermediateDirectory)/World.cpp$(ObjectSuffix): World.cpp $(IntermediateDirectory)/World.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/World.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/World.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/World.cpp$(DependSuffix): World.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/World.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/World.cpp$(DependSuffix) -MM World.cpp

$(IntermediateDirectory)/World.cpp$(PreprocessSuffix): World.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/World.cpp$(PreprocessSuffix) World.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Label.cpp$(ObjectSuffix): Label.cpp $(IntermediateDirectory)/Label.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/Label.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Label.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Label.cpp$(DependSuffix): Label.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Label.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Label.cpp$(DependSuffix) -MM Label.cpp

$(IntermediateDirectory)/Label.cpp$(PreprocessSuffix): Label.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Label.cpp$(PreprocessSuffix) Label.cpp

$(IntermediateDirectory)/Player.cpp$(ObjectSuffix): Player.cpp $(IntermediateDirectory)/Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Player.cpp$(DependSuffix): Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Player.cpp$(DependSuffix) -MM Player.cpp

$(IntermediateDirectory)/Player.cpp$(PreprocessSuffix): Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Player.cpp$(PreprocessSuffix) Player.cpp

$(IntermediateDirectory)/GameOverState.cpp$(ObjectSuffix): GameOverState.cpp $(IntermediateDirectory)/GameOverState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/GameOverState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameOverState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameOverState.cpp$(DependSuffix): GameOverState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameOverState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameOverState.cpp$(DependSuffix) -MM GameOverState.cpp

$(IntermediateDirectory)/GameOverState.cpp$(PreprocessSuffix): GameOverState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameOverState.cpp$(PreprocessSuffix) GameOverState.cpp

$(IntermediateDirectory)/Spacecraft.cpp$(ObjectSuffix): Spacecraft.cpp $(IntermediateDirectory)/Spacecraft.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/Spacecraft.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Spacecraft.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Spacecraft.cpp$(DependSuffix): Spacecraft.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Spacecraft.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Spacecraft.cpp$(DependSuffix) -MM Spacecraft.cpp

$(IntermediateDirectory)/Spacecraft.cpp$(PreprocessSuffix): Spacecraft.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Spacecraft.cpp$(PreprocessSuffix) Spacecraft.cpp

$(IntermediateDirectory)/Component.cpp$(ObjectSuffix): Component.cpp $(IntermediateDirectory)/Component.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/Component.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Component.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Component.cpp$(DependSuffix): Component.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Component.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Component.cpp$(DependSuffix) -MM Component.cpp

$(IntermediateDirectory)/Component.cpp$(PreprocessSuffix): Component.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Component.cpp$(PreprocessSuffix) Component.cpp

$(IntermediateDirectory)/Utility.cpp$(ObjectSuffix): Utility.cpp $(IntermediateDirectory)/Utility.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/Utility.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Utility.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Utility.cpp$(DependSuffix): Utility.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Utility.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Utility.cpp$(DependSuffix) -MM Utility.cpp

$(IntermediateDirectory)/Utility.cpp$(PreprocessSuffix): Utility.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Utility.cpp$(PreprocessSuffix) Utility.cpp

$(IntermediateDirectory)/TitleLoadTask.cpp$(ObjectSuffix): TitleLoadTask.cpp $(IntermediateDirectory)/TitleLoadTask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/TitleLoadTask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TitleLoadTask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TitleLoadTask.cpp$(DependSuffix): TitleLoadTask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TitleLoadTask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TitleLoadTask.cpp$(DependSuffix) -MM TitleLoadTask.cpp

$(IntermediateDirectory)/TitleLoadTask.cpp$(PreprocessSuffix): TitleLoadTask.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TitleLoadTask.cpp$(PreprocessSuffix) TitleLoadTask.cpp

$(IntermediateDirectory)/TitleLoadState.cpp$(ObjectSuffix): TitleLoadState.cpp $(IntermediateDirectory)/TitleLoadState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/TitleLoadState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TitleLoadState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TitleLoadState.cpp$(DependSuffix): TitleLoadState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TitleLoadState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TitleLoadState.cpp$(DependSuffix) -MM TitleLoadState.cpp

$(IntermediateDirectory)/TitleLoadState.cpp$(PreprocessSuffix): TitleLoadState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TitleLoadState.cpp$(PreprocessSuffix) TitleLoadState.cpp

$(IntermediateDirectory)/StringHelpers.cpp$(ObjectSuffix): StringHelpers.cpp $(IntermediateDirectory)/StringHelpers.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/StringHelpers.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/StringHelpers.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/StringHelpers.cpp$(DependSuffix): StringHelpers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/StringHelpers.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/StringHelpers.cpp$(DependSuffix) -MM StringHelpers.cpp

$(IntermediateDirectory)/StringHelpers.cpp$(PreprocessSuffix): StringHelpers.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/StringHelpers.cpp$(PreprocessSuffix) StringHelpers.cpp

$(IntermediateDirectory)/StateStack.cpp$(ObjectSuffix): StateStack.cpp $(IntermediateDirectory)/StateStack.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/StateStack.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/StateStack.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/StateStack.cpp$(DependSuffix): StateStack.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/StateStack.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/StateStack.cpp$(DependSuffix) -MM StateStack.cpp

$(IntermediateDirectory)/StateStack.cpp$(PreprocessSuffix): StateStack.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/StateStack.cpp$(PreprocessSuffix) StateStack.cpp

$(IntermediateDirectory)/State.cpp$(ObjectSuffix): State.cpp $(IntermediateDirectory)/State.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/State.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/State.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/State.cpp$(DependSuffix): State.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/State.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/State.cpp$(DependSuffix) -MM State.cpp

$(IntermediateDirectory)/State.cpp$(PreprocessSuffix): State.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/State.cpp$(PreprocessSuffix) State.cpp

$(IntermediateDirectory)/SpriteNode.cpp$(ObjectSuffix): SpriteNode.cpp $(IntermediateDirectory)/SpriteNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/SpriteNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SpriteNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SpriteNode.cpp$(DependSuffix): SpriteNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SpriteNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SpriteNode.cpp$(DependSuffix) -MM SpriteNode.cpp

$(IntermediateDirectory)/SpriteNode.cpp$(PreprocessSuffix): SpriteNode.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SpriteNode.cpp$(PreprocessSuffix) SpriteNode.cpp

$(IntermediateDirectory)/SettingsState.cpp$(ObjectSuffix): SettingsState.cpp $(IntermediateDirectory)/SettingsState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/SettingsState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SettingsState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SettingsState.cpp$(DependSuffix): SettingsState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SettingsState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SettingsState.cpp$(DependSuffix) -MM SettingsState.cpp

$(IntermediateDirectory)/SettingsState.cpp$(PreprocessSuffix): SettingsState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SettingsState.cpp$(PreprocessSuffix) SettingsState.cpp

$(IntermediateDirectory)/SceneNode.cpp$(ObjectSuffix): SceneNode.cpp $(IntermediateDirectory)/SceneNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/SceneNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SceneNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SceneNode.cpp$(DependSuffix): SceneNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SceneNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SceneNode.cpp$(DependSuffix) -MM SceneNode.cpp

$(IntermediateDirectory)/SceneNode.cpp$(PreprocessSuffix): SceneNode.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SceneNode.cpp$(PreprocessSuffix) SceneNode.cpp

$(IntermediateDirectory)/Pickup.cpp$(ObjectSuffix): Pickup.cpp $(IntermediateDirectory)/Pickup.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/Pickup.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Pickup.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Pickup.cpp$(DependSuffix): Pickup.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Pickup.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Pickup.cpp$(DependSuffix) -MM Pickup.cpp

$(IntermediateDirectory)/Pickup.cpp$(PreprocessSuffix): Pickup.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Pickup.cpp$(PreprocessSuffix) Pickup.cpp

$(IntermediateDirectory)/PauseState.cpp$(ObjectSuffix): PauseState.cpp $(IntermediateDirectory)/PauseState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Retrofit/CodeLite/Workspaces/StarFleet/StarFleet/PauseState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PauseState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PauseState.cpp$(DependSuffix): PauseState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PauseState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PauseState.cpp$(DependSuffix) -MM PauseState.cpp

$(IntermediateDirectory)/PauseState.cpp$(PreprocessSuffix): PauseState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PauseState.cpp$(PreprocessSuffix) PauseState.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


