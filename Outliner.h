#pragma once
#include <windows.h>
#include <commctrl.h>
#include "pstring.h"
#include "WinDat.h"

#define MAX_RESOURCE_NUM 512
#define MAX_RESOURCE_CAMERA 32
#define MAX_RESOURCE_MESHGEO 32
#define MAX_RESOURCE_SCENE 32
#define MAX_RESOURCE_TRIGGER 32
#define MAX_RESOURCE_SHADER 32
#define MAX_RESOURCE_TEXTURE 32
#define MAX_RESOURCE_LIGHT 32
#define MAX_AMALGAMATES_MATERIALS 32
#define MAX_AMALGAMATES_MODELS 32

#define MAX_SCENE_INSTANCE_MODEL 32
#define MAX_SCENE_INSTANCE_CAMERA 32
#define MAX_SCENE_INSTANCE_LIGHT 32
#define MAX_SCENE_INSTANCE_TRIGGER 32

enum ResourceType {
	Texture_R_TYPE, MeshGeo_R_TYPE, PixelShader_R_TYPE, VertexShader_R_TYPE, Light_R_TYPE
};



class Resource {

public:
	Resource();
	~Resource();
private:

	int numOfInstances;
	int ResourceType;
	int isLoaded;
	int resourceID;
	PString resourceName;

};


class Amalgamate {
public:
	PString aName;
	int aId;
	int aType;
	int numOfInstances;
private:
};

class Instance {

	float x;
	float y;
	float z;
	float dx;
	float dy;
	float dz;
	bool draw;
	bool update;
	bool loaded;

	PString iName;
	int iID;
};


class Camera : private Instance {
	
};

class Model : private Instance {

public:
private:

};

class ModelPart : private Amalgamate {

	int modelPartID;
	int materialID;

};

class Light : private Resource {

};


class MeshGeo : private Resource {
	int VertexType;

	LONG geo;
};

class Trigger : private Resource {
};

class Scene{

public:
	Scene();

	void NewScene(PString name);

	void SetActive(int a);
	void AddCamera(int inst);
	void AddModel(int inst);
	void AddLight(int inst);
	void AddTrigger(int inst);
private:
	int cameras[MAX_SCENE_INSTANCE_CAMERA];
	int models[MAX_SCENE_INSTANCE_MODEL];
	int lights[MAX_SCENE_INSTANCE_LIGHT];
	int triggers[MAX_SCENE_INSTANCE_TRIGGER];
	int numCameras;
	int numModels;
	int numLights;
	int numTriggers;
	int numObjects;
	int sceneID;
	bool active;
	bool doesUpdate;
	bool doesDraw;

	PString sceneName;

};

class Texture : private Resource {
public:
	Texture();
};


class Material : private Amalgamate {

public:
	Material();

private:
	int PixelShaderID;
	int VertexShaderID;
	int diffuseTexID;
	int specTexID;
	int normalTexID;
};



class ResourceGraph {

public:
	ResourceGraph();

	void AddScene(PString name);

	Resource* GetResource(PString rName);
	Amalgamate* GetAmalgamate(PString pName);

private:

	Texture textures[MAX_RESOURCE_TEXTURE];
	MeshGeo meshGeo[MAX_RESOURCE_MESHGEO];


	Scene scenes[MAX_RESOURCE_SCENE];
	Material materials[MAX_AMALGAMATES_MATERIALS];

	int numTextures;
	int numScenes;

	int uniqueResources;
	int uniqueAmalgamates;
};




class OutLiner {

public:
	OutLiner();
	void CreateOutLiner(WinDat& wd);
	void SetResourceGraph(ResourceGraph* r);

	void AddItem(HTREEITEM hItem, LPWSTR lpstr);
private:

	HTREEITEM items[50];
	int numItems;

	HTREEITEM hRoot;

	WinDat* windowData;
	ResourceGraph* rg;
};