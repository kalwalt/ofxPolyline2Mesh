#include "ofApp.h"

void ofApp::reset_polyline(){
    mesh.clear();

        float s = 300;

        {
            ofMesh m;
            m.setMode(OF_PRIMITIVE_LINE_STRIP);

            for (int i = 0; i < 10; i++)
            {
                ofVec3f v;
                v.x = ofRandom(-s, s);
                v.y = ofRandom(-s, s);
                v.z = ofRandom(-s, s);

                m.addColor(ofColor::fromHsb(ofRandom(255), 255, 255));
                m.addVertex(v);
            }
            mesh.add(m);
        }

        {
                ofMesh m;
                m.setMode(OF_PRIMITIVE_LINES);

                for (int i = 0; i < 10; i++)
                {
                    ofVec3f v;
                    v.x = ofRandom(-s, s);
                    v.y = ofRandom(-s, s);
                    v.z = ofRandom(-s, s);

                    m.addColor(ofColor::fromHsb(ofRandom(255), 255, 255));
                    m.addVertex(v);
                }
                mesh.add(m);
            }

        {
                ofMesh m;
                m.setMode(OF_PRIMITIVE_TRIANGLES);

                for (int i = 0; i < 12; i++)
                {
                    ofVec3f v;
                    v.x = ofRandom(-s, s);
                    v.y = ofRandom(-s, s);
                    v.z = ofRandom(-s, s);

                    m.addColor(ofColor::fromHsb(ofRandom(255), 255, 255));
                    m.addVertex(v);
                }
                mesh.add(m);
            }

            {
                ofMesh m;
                m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

                for (int i = 0; i < 12; i++)
                {
                    ofVec3f v;
                    v.x = ofRandom(-s, s);
                    v.y = ofRandom(-s, s);
                    v.z = ofRandom(-s, s);

                    m.addColor(ofColor::fromHsb(ofRandom(255), 255, 255));
                    m.addVertex(v);
                }
                mesh.add(m);
            }


}

//--------------------------------------------------------------
void ofApp::setup(){

        ofSetVerticalSync(true);
        ofSetFrameRate(60);

        ofSetColor(255, 0, 0);
        ofBackground(255);

        ofSetLineWidth(30);
        reset_polyline();

        ofSetGlobalAmbientColor(ofColor(180));
}

//--------------------------------------------------------------
void ofApp::update(){
        render_mesh = mesh.getMesh();
}

//--------------------------------------------------------------
void ofApp::draw(){

        ofEnableDepthTest();

        light.enable();
        light.setPosition(0, -500, 500);

        cam.begin();

        ofRotate(ofGetElapsedTimef() * 20, 0, 1, 0);

        render_mesh.draw();

        cam.end();

        light.disable();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
        if (key == ' ')
            reset_polyline();
        else if (key == 's')
            mesh.save("out.obj");
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
