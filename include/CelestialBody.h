#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <string>
#include <vector>

class CelestialBody;

namespace Celestial
{
  // TODO: Add to CelestialBody class as static members
  void sort(std::vector<CelestialBody>& SolarSystem);
  void setBounds(const std::vector<CelestialBody>& SolarSystem);

  void setSmallestRadius(const std::vector<CelestialBody>& SolarSystem);
  void setSmallestOrbitRadius(const std::vector<CelestialBody>& SolarSystem);
  void setGreatestRadius(const std::vector<CelestialBody>& SolarSystem);
  void setGreatestOrbitRadius(const std::vector<CelestialBody>& SolarSystem);

  static double smallestRadius;
  static double smallestOrbitRadius;
  static double greatestRadius;
  static double greatestOrbitRadius;
  static double scaleTargetMinRadiusSize;
  static double scaleTargetMaxRadiusSize;
  static double scaleTargetMinOrbitRadiusSize;
  static double scaleTargetMaxOrbitRadiusSize;
}

class CelestialBody
{
private:
  // TODO: Add to CelestialBody class as static members
  friend void Celestial::setSmallestRadius(const std::vector<CelestialBody>& SolarSystem);
  friend void Celestial::setSmallestOrbitRadius(const std::vector<CelestialBody>& SolarSystem);
  friend void Celestial::setGreatestRadius(const std::vector<CelestialBody>& SolarSystem);
  friend void Celestial::setGreatestOrbitRadius(const std::vector<CelestialBody>& SolarSystem);

public:
  CelestialBody(const std::string& name, const char* fileName, double mass, double volume, double density, double gravity, double radius, double velocity, double perihelion, double aphelion, double orbit, double rotation, int satellites, bool ring);
  ~CelestialBody() { };

private:
  double logScale(double value, const std::string& type) const;

public:
  double getDistance(const CelestialBody& compare) const;
  double getAttractionForce(const CelestialBody& compare) const;

public:
  // Accessors
  std::string getName() const { return this->name; }
  const char* getFileName() const { return this->fileName; }
  double getMass() const { return this->mass; }
  double getVolume() const { return this->volume; }
  double getDensity() const { return this->density; }
  double getGravity() const { return this->gravity; }
  double getRadius() const { return logScale(this->radius, "radius"); }
  double getVelocity() const { return this->velocity; }
  double getPerihelion() const { return this->perihelion; }
  double getAphelion() const { return this->aphelion; }
  double getOrbit() const { return this->orbit; }
  double getOrbitRadius() const { return logScale(this->orbitRadius, "orbitRadius"); }
  double getAxisRotation() const { return this->rotation; }
  int getSatellites() const { return this->satellites; }
  bool getRing() const { return this->ring; }

private: 
  const std::string name;
  const char* fileName;
  const double mass;
  const double volume;
  const double density;
  const double gravity;
  const double radius;
  const double velocity;
  const double perihelion;
  const double aphelion;
  const double orbit;
  const double orbitRadius;
  const double rotation;
  const int satellites;
  const bool ring;
};

#endif // CELESTIALBODY_H
