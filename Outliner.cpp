#include "Outliner.h"

Resource::Resource()
{
}

Resource::~Resource()
{
}

ResourceGraph::ResourceGraph()
{
}

void ResourceGraph::AddScene(PString name){
	scenes[numScenes++].NewScene(name);
}

Resource * ResourceGraph::GetResource(PString rName)
{
	return nullptr;
}

Amalgamate * ResourceGraph::GetAmalgamate(PString pName)
{
	return nullptr;
}

Material::Material()
{
}

Texture::Texture()
{
}

Scene::Scene() : numCameras(0), numModels(0), numLights(0), numTriggers(0), numObjects(0), sceneID(-1){

}

void Scene::NewScene(PString n) {
	sceneName = n;
	SetActive(1);
}
void Scene::SetActive(int a) {
	switch (a) {
	case 0: 
		active = doesUpdate = doesDraw = false;
		break;
	case 1:
		active = doesUpdate = doesDraw = true;
		break;
	case 2:
		active = doesUpdate = true;
		doesDraw = false;
		break;
	case 3:
		active = doesDraw = true;
		doesUpdate = false;
		break;

	}

}

void Scene::AddCamera(int inst){
	cameras[numCameras++] = inst;
	numObjects++;
}

void Scene::AddModel(int inst){
	cameras[numModels++] = inst;
	numObjects++;
}
void Scene::AddLight(int inst){
	cameras[numLights++] = inst;
	numObjects++;
}
void Scene::AddTrigger(int inst){
	cameras[numTriggers++] = inst;
	numObjects++;
}



OutLiner::OutLiner(){

}


void OutLiner::CreateOutLiner(WinDat& wd) {
	windowData = &wd;


	wd._handle = CreateWindowEx(0, wd._className, NULL, wd._style, wd._x, wd._y, wd._w, wd._h, wd._parent, 0, NULL, NULL);



	TV_INSERTSTRUCT tvins;

	tvins = { 0 };

	tvins.hInsertAfter = TVI_ROOT;
	tvins.item.mask = TVIF_TEXT;
	tvins.item.pszText = L"Root";
	tvins.item.cchTextMax = 10;

	hRoot = TreeView_InsertItem(wd._handle, &tvins);
}
void OutLiner::SetResourceGraph(ResourceGraph* r) {

}


void OutLiner::AddItem(HTREEITEM hItem, LPWSTR lpstr) {



}
