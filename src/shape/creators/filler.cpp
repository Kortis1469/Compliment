#include "filler.h"


void SolidFiller::fill(std::vector<point> &pts) const
{

    std::vector<point> buffer;
    std::vector<point> line;
    std::vector<point> inerReg = pts;
    std::sort(inerReg.begin(),inerReg.end(),ComporatorLinScan::compare);

    for(size_t i = 0; i<inerReg.size()-1;i++){
        if(inerReg[i].y == inerReg[i+1].y){
            line = lineCr.createLine(inerReg[i].x,inerReg[i].y,inerReg[i+1].x,inerReg[i].y);
            buffer.insert(buffer.end(), line.begin(), line.end());
        }
    }
    inerReg.insert(inerReg.end(), buffer.begin(), buffer.end());

    pts = inerReg;
}



void DonatFiller::fill(std::vector<point> &externalOutline, int innerRadius, int xc, int yc) const
{
    std::vector<point> buffer;
    std::vector<point> line;
    std::vector<point> inerReg = externalOutline;
    std::sort(inerReg.begin(),inerReg.end(),ComporatorLinScan::compare);


    for(size_t i = 0; i<inerReg.size()-1;i++){
        if(inerReg[i].y == inerReg[i+1].y){
            line = lineCr.createLine(inerReg[i].x,inerReg[i].y,inerReg[i+1].x,inerReg[i].y);
            buffer.insert(buffer.end(), line.begin(), line.end());
        }
    }
    inerReg.insert(inerReg.end(), buffer.begin(), buffer.end());

    std::vector<point> filtered;
    filtered.reserve(inerReg.size());

    for (auto &p : inerReg) {
        int dx = p.x - xc;
        int dy = p.y - yc;
        int dist = std::sqrt(dx*dx + dy*dy);

        if (dist >= innerRadius) {
            filtered.push_back(p);
        }
    }

    inerReg.swap(filtered);


    externalOutline = inerReg;
}

Filler::Filler():
lineCr()
{
}
