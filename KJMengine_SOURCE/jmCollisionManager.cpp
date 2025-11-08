#include "jmCollisionManager.h"
#include "jmScene.h"
#include "jmSceneManager.h"
#include "jmGameObject.h"
#include "jmCollider.h"
#include "jmTransform.h"

namespace jm
{

	std::bitset<(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{
		int a = 1;
		int b = a << 1;
	}

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();

		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}

	void CollisionManager::LateUpdate()
	{

	}

	void CollisionManager::Render(HDC hdc)
	{

	}
	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		mCollisionLayerMatrix[row][col] = enable;
	}
	void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
	{
		const std::vector<GameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
		const std::vector<GameObject*>& rights = scene->GetLayer(right)->GetGameObjects();

		for (GameObject* left : lefts)
		{
			if (left->IsActive() == false)
				continue;
			Collider* leftCol = left->GetComponent<Collider>();
			if (leftCol == nullptr)
				continue;

			for (GameObject* right : rights)
			{
				if (right->IsActive() == false)
					continue;

				Collider* rightCol = right->GetComponent<Collider>();
				if (rightCol == nullptr)
					continue;
				if (left == right)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}
	}
	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		// 충돌체의 ID 대입 (플레이어 몬스터 등등)
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		// 이전 충돌정보를 검색하고 만약 없다면 충돌정보를 생성한다.
		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		// 충돌체크
		if (Intersect(left, right))
		{
			// 충돌진입
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			// 충돌중
			else
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		// 충돌끝
		else
		{
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}
	}

	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* lefttr = left->GetOwner()->GetComponent<Transform>();
		Transform* righttr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftpos = lefttr->GetPosition() + left->Getoffset();
		Vector2 rightpos = righttr->GetPosition() + right->Getoffset();

		Vector2 leftsize = left->GetSize() * 100.0f;
		Vector2 rightsize = right->GetSize() * 100.0f;
		
		enums::eColliderType leftType = left->GetColliderType();
		enums::eColliderType rightType = right->GetColliderType();

		if (leftType == enums::eColliderType::Rect2D
			&& rightType == enums::eColliderType::Rect2D)
		{
			if (fabs(leftpos.x - rightpos.x) < fabs(leftsize.x / 2.0f + rightsize.x / 2.0f)
				&& fabs(leftpos.y - rightpos.y) < fabs(leftsize.y / 2.0f + rightsize.y / 2.0f))
			{
				return true;
			}
		}

		if (leftType == enums::eColliderType::Circle2D
			&& rightType == enums::eColliderType::Circle2D)
		{
			Vector2 leftCirclePos = leftpos + (leftsize / 2.0f);
			Vector2 rightCirclePos = rightpos + (rightsize / 2.0f);
			float distance = (leftCirclePos - rightCirclePos).length();
			if (distance <= (leftsize.x / 2.0f + rightsize.x / 2.0f))
			{
				return true;
			}
		}

		if ((leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Rect2D)
			|| (leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Circle2D))
		{
			Vector2 circlePos, rectPos;
			Vector2 circleSize, rectSize;

			if (leftType == enums::eColliderType::Circle2D)
			{
				circlePos = leftpos;
				circleSize = leftsize;
				rectPos = rightpos;
				rectSize = rightsize;
			}
			else
			{
				circlePos = rightpos;
				circleSize = rightsize;
				rectPos = leftpos;
				rectSize = leftsize;
			}
		}

		return false;
	}
}