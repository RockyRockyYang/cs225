#include "scene.h"
#include "image.h"
#include <iostream>
#include <cstdlib>

using namespace std;

	Scene::Scene(int m) {
		max = m;
		layers = new Image *[m];
		x = new int[m];
		y = new int[m];
		for(int i=0; i<m; i++){
			layers[i] = NULL;
			//x[i] = 0;
			//y[i] = 0;		
		}
	}

	Scene::~Scene() {
		for(int i=0; i<max; i++){
			delete layers[i];
		}
			delete []layers;
			delete []x;
			delete []y;
	}
	
	Scene::Scene(const Scene & source) {
		copy(source);
	}

	const Scene & Scene::operator=(const Scene & source) {
		if(this != &source) {
			clear();
			copy(source);
		}
			return (*this);			
	}	

	void Scene::changemaxlayers(int newmax) {
		
		int count = 0;
		for(int i=0; i<max; i++) {
			if(layers[i] != NULL)
				count++;
		}
		if(newmax < count) {	
			cout<<"invalid newmax"<<endl;
			return;
		}
		Image** nlayers = new Image *[newmax];
		int *nx = new int[newmax];
		int *ny = new int[newmax];
		for(int i=0; i<newmax; i++) {
			nlayers[i] = NULL;
			nx[i] =0;
			ny[i] =0;
		}
		for(int i=0; i<max; i++) {
			if(layers[i] != NULL) {
				*nlayers[i] = *layers[i];
				nx[i] = x[i];
				ny[i] = y[i];
			}
		}
		//clear();
		delete[] x;
		delete[] y;
		for(int j=0; j< max; j++) {
			layers[j] = NULL;
		}
		delete [] layers;

		layers = nlayers;
		x = nx;
		y = ny;
		max = newmax;
		nlayers = NULL;
		nx = NULL;
		ny = NULL;
	}
	
	void Scene::addpicture(const char * FileName, int index, int ax, int ay) {
		if(index >=0 && index<max) {
			if(layers[index] != NULL) {
				delete layers[index];
			}
			Image * p = new Image();
			p->readFromFile(FileName);
			layers[index] = p;
			x[index] = ax;			
			y[index] = ay;
		}
		else
			cout<<"index out of bounds"<<endl;
	}

	void Scene::changelayer(int index, int newindex) {
		if(index >=0 && index <max && newindex >=0 && newindex <max) {
			if(index == newindex)
				return;
			        if(layers[newindex]!=NULL)
            				delete layers[newindex];
        				
        			layers[newindex] = layers[index];
        			layers[index] = NULL;
        			
        			x[newindex] = x[index];
        			y[newindex] = y[index];
       				x[index] = 0;
        			y[index] = 0;
			
		}
		else
			cout<<"invalid index"<<endl;
	}

	void Scene::translate(int index, int xcoord, int ycoord) {
		if(index >=0 && index <max && layers[index] != NULL) {
			x[index] = xcoord;
			y[index] = ycoord;
		}
		else
			cout<<"invalid index"<<endl;
	}	

	void Scene::deletepicture(int index) {
		if(index >=0 && index <max && layers[index] != NULL) {
			delete layers[index];
			layers[index] = NULL;
			x[index] = 0;
			y[index] = 0;	
		}
		else {
			cout<<"invalid index"<<endl;
		}	
	}
	
	Image* Scene::getpicture(int index) const {
		if(index >=0 && index <max) {
			return layers[index];
		}
		else {
			cout<<"invalid index"<<endl;
			return NULL;
		}					
	}

	Image Scene::drawscene() const {
		int mwidth =0;
		int mheight = 0;
		for(int i=0; i<max; i++) {
			if(layers[i] != NULL) {
			if((int)(*layers[i]).width()+ x[i] > mwidth)
				mwidth = (*layers[i]).width() + x[i];
			if((int)(*layers[i]).height()+ y[i] >mheight)
				mheight = (*layers[i]).height() + y[i];
			}
		}
		Image output;
		output.resize(mwidth, mheight);

		for(int i=0; i<max; i++) {
			if(layers[i] != NULL) {
				for(int xi=0; xi<(int)(*layers[i]).width(); xi++) {
					for(int yi=0; yi<(int)(*layers[i]).height(); yi++) {
					*output(x[i]+xi, y[i]+yi) = *(*layers[i])(xi,yi);
					}
				}
			}
		}
		return output;
	}


	void Scene::clear() {
		for(int i=0; i<max; i++){
			delete layers[i];
			layers[i] = NULL;
		}
			delete []layers;
			delete []x;
			delete []y;
	}

	void Scene::copy(const Scene & source) {
		max = source.max;
		layers = new Image *[max];
		x = new int[max];
		y = new int[max];
		for(int i=0; i< max; i++) {
			x[i] = source.x[i];
			y[i] = source.y[i];
			if(source.layers[i] == NULL)
				layers[i] = NULL;
			else
				layers[i] = new Image(*(source.layers[i]));
		}				
	}


