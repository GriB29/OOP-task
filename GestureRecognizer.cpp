#include "GestureRecognizer.h"
#include <cmath>

GestureType GestureRecognizer::recognizeGesture(
    const std::vector<sf::Vector2f>& points,
    sf::FloatRect cellBounds)
{
    if(points.size()<10)
        return GestureType::None;

    std::vector<sf::Vector2f> localPoints;

    for(const auto& p:points)
    {
        float localX=(p.x-cellBounds.left)/cellBounds.width;
        float localY=(p.y-cellBounds.top)/cellBounds.height;

        localPoints.emplace_back(localX,localY);
    }

    float distStartToEnd=std::hypot(
        localPoints.front().x-localPoints.back().x,
        localPoints.front().y-localPoints.back().y
    );

    bool isClosed=(distStartToEnd<0.3f);

    int pointsOnPerimeter=0;

    for(const auto& p:localPoints)
    {
        float dist=std::hypot(p.x-0.5f,p.y-0.5f);

        if(dist>0.25f && dist<0.6f)
            pointsOnPerimeter++;
    }

    bool looksLikeCircle=
        isClosed &&
        (pointsOnPerimeter>localPoints.size()*0.6f);

    if(looksLikeCircle)
        return GestureType::Circle;

    bool tl=false,br=false,tr=false,bl=false;

    for(const auto& p:localPoints)
    {
        if(p.x<0.3f && p.y<0.3f) tl=true;
        if(p.x>0.7f && p.y>0.7f) br=true;
        if(p.x>0.7f && p.y<0.3f) tr=true;
        if(p.x<0.3f && p.y>0.7f) bl=true;
    }

    if((tl && br)||(tr && bl))
        if(points.size()>15)
            return GestureType::Cross;

    return GestureType::None;
}