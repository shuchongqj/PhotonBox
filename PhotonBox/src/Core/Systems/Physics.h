#ifndef PHYSICS_H
#define PHYSICS_H

class Collider;
class Rigidbody;
class Entity;
#include <vector>
#include <map>

#include "PxPhysicsAPI.h"

using namespace physx;

class Physics
{
public:
	static const double FIXED_TIME_INTERVAL;

	static void addToPhysicsList(Collider *collider);
	static void addToPhysicsList(Rigidbody *rigidbody);
	static void removeFromPhysicsList(Collider* collider);
	static void removeFromPhysicsList(Rigidbody *rigidbody);

	static void addPhysicsObject(Rigidbody* rigidbody); // , Collider* collider);
	static void printList();
	static std::string getList();

	static PxRigidDynamic* createDynamic(const PxTransform& t, const PxGeometry& geometry, const PxVec3& velocity = PxVec3(0))
	{
		PxRigidDynamic* dynamic = PxCreateDynamic(*_gPhysics, t, geometry, *_gMaterial, 10.0f);
		_gScene->addActor(*dynamic);

		
		return dynamic;
	}

	void init();
	void update();
	void reset();
	void destroy();
private:
	static std::vector<Collider*> _colliders;
	static std::vector<Rigidbody*> _rigidbodies;
	static std::map<PxActor*, Entity*> _physXMap;



	PxDefaultAllocator		_gAllocator;
	PxDefaultErrorCallback	_gErrorCallback;

	PxFoundation*			_gFoundation = NULL;
	static PxPhysics*				_gPhysics;

	PxDefaultCpuDispatcher*	_gDispatcher = NULL;
	static PxScene*				_gScene;

	static PxMaterial* _gMaterial;
	static PxSceneDesc* _sceneDesc;
};

#endif // PHYSICS_H
