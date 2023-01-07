#pragma once

#pragma comment(lib, "BlueBlur.lib")

#if (defined(_ITERATOR_DEBUG_LEVEL) && _ITERATOR_DEBUG_LEVEL != 0) || defined(_MAP_) || defined(_XTREE_)
#if defined(_VECTOR_) || defined(_LIST_) || defined(_MAP_) || defined(_XTREE_)
#error "BlueBlur must be included before STL"
#endif
#endif

#pragma push_macro("_ITERATOR_DEBUG_LEVEL")
#undef _ITERATOR_DEBUG_LEVEL
#define _ITERATOR_DEBUG_LEVEL 0

#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/Container/hhList.h>
#include <Hedgehog/Base/Container/hhVector.h>

#undef _ITERATOR_DEBUG_LEVEL
#pragma pop_macro("_ITERATOR_DEBUG_LEVEL")

#include <Hedgehog/Animation/hhAnimationPose.h>
#include <Hedgehog/Animation/hhPose.h>
#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/hhRefCountObject.h>
#include <Hedgehog/Base/Platform/D3D9/hhCriticalSectionD3D9.h>
#include <Hedgehog/Base/System/hhAllocator.h>
#include <Hedgehog/Base/System/hhSymbol.h>
#include <Hedgehog/Base/Thread/hhHolder.h>
#include <Hedgehog/Base/Thread/hhHolderBase.h>
#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>
#include <Hedgehog/Base/Thread/hhSynchronizedPtr.h>
#include <Hedgehog/Base/Thread/hhSynchronizedPtrBase.h>
#include <Hedgehog/Base/Type/hhCowData.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Database/System/hhArchiveDatabaseLoader.h>
#include <Hedgehog/Database/System/hhArchiveParam.h>
#include <Hedgehog/Database/System/hhDatabase.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>
#include <Hedgehog/Database/System/hhDatabaseLoader.h>
#include <Hedgehog/Database/System/hhRawData.h>
#include <Hedgehog/FxRenderFramework/hhDrawInstanceParam.h>
#include <Hedgehog/FxRenderFramework/hhScreenRenderParam.h>
#include <Hedgehog/MirageCore/Camera/hhCamera.h>
#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.h>
#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNodeListener.h>
#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNodeNormal.h>
#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNodeSingleElementNode.h>
#include <Hedgehog/MirageCore/Misc/hhDirector.h>
#include <Hedgehog/MirageCore/Misc/hhInstanceInfo.h>
#include <Hedgehog/MirageCore/Misc/hhLightManager.h>
#include <Hedgehog/MirageCore/Misc/hhPrimitive.h>
#include <Hedgehog/MirageCore/Misc/hhRenderingDevice.h>
#include <Hedgehog/MirageCore/Misc/hhRenderingInfrastructure.h>
#include <Hedgehog/MirageCore/Misc/hhRenderScene.h>
#include <Hedgehog/MirageCore/Misc/hhSamplerState.h>
#include <Hedgehog/MirageCore/Misc/hhStaticLightContext.h>
#include <Hedgehog/MirageCore/Misc/hhTransform.h>
#include <Hedgehog/MirageCore/Misc/hhVertexDeclarationPtr.h>
#include <Hedgehog/MirageCore/Renderable/hhBundle.h>
#include <Hedgehog/MirageCore/Renderable/hhElement.h>
#include <Hedgehog/MirageCore/Renderable/hhOptimalBundle.h>
#include <Hedgehog/MirageCore/Renderable/hhRenderable.h>
#include <Hedgehog/MirageCore/Renderable/hhSingleElement.h>
#include <Hedgehog/MirageCore/Renderable/hhTerrainRenderable.h>
#include <Hedgehog/MirageCore/RenderData/hhLightData.h>
#include <Hedgehog/MirageCore/RenderData/hhLightListData.h>
#include <Hedgehog/MirageCore/RenderData/hhMaterialData.h>
#include <Hedgehog/MirageCore/RenderData/hhMeshData.h>
#include <Hedgehog/MirageCore/RenderData/hhMirageDatabaseWrapper.h>
#include <Hedgehog/MirageCore/RenderData/hhModelData.h>
#include <Hedgehog/MirageCore/RenderData/hhNodeGroupModelData.h>
#include <Hedgehog/MirageCore/RenderData/hhParameterElement.h>
#include <Hedgehog/MirageCore/RenderData/hhPictureData.h>
#include <Hedgehog/MirageCore/RenderData/hhPixelShaderCodeData.h>
#include <Hedgehog/MirageCore/RenderData/hhPixelShaderData.h>
#include <Hedgehog/MirageCore/RenderData/hhShaderListData.h>
#include <Hedgehog/MirageCore/RenderData/hhTerrainInstanceInfoData.h>
#include <Hedgehog/MirageCore/RenderData/hhTerrainModelData.h>
#include <Hedgehog/MirageCore/RenderData/hhTexsetData.h>
#include <Hedgehog/MirageCore/RenderData/hhTextureData.h>
#include <Hedgehog/MirageCore/RenderData/hhVertexShaderCodeData.h>
#include <Hedgehog/MirageCore/RenderData/hhVertexShaderData.h>
#include <Hedgehog/MotionCore/MotionData/hhLightMotionData.h>
#include <Hedgehog/MotionCore/MotionData/hhMotionDatabaseWrapper.h>
#include <Hedgehog/Universe/Engine/hhMessage.h>
#include <Hedgehog/Universe/Engine/hhMessageActor.h>
#include <Hedgehog/Universe/Engine/hhMessageManager.h>
#include <Hedgehog/Universe/Engine/hhMessageProcess.h>
#include <Hedgehog/Universe/Engine/hhStateMachine.h>
#include <Hedgehog/Universe/Engine/hhStateMachineBase.h>
#include <Hedgehog/Universe/Engine/hhStateMachineMessageReceiver.h>
#include <Hedgehog/Universe/Engine/hhUpdateInfo.h>
#include <Hedgehog/Universe/Engine/hhUpdateManager.h>
#include <Hedgehog/Universe/Engine/hhUpdateUnit.h>
#include <Hedgehog/Universe/Thread/hhParallelJob.h>
#include <Hedgehog/Utility/hhScopedPointerVector.h>
#include <Hedgehog/Yggdrasill/hhYggAbstractBuffer.h>
#include <Hedgehog/Yggdrasill/hhYggAllocator.h>
#include <Hedgehog/Yggdrasill/hhYggDevice.h>
#include <Hedgehog/Yggdrasill/hhYggJob.h>
#include <Hedgehog/Yggdrasill/hhYggMisc.h>
#include <Hedgehog/Yggdrasill/hhYggPicture.h>
#include <Hedgehog/Yggdrasill/hhYggSceneRenderer.h>
#include <Hedgehog/Yggdrasill/hhYggScheduler.h>
#include <Hedgehog/Yggdrasill/hhYggSurface.h>
#include <Hedgehog/Yggdrasill/hhYggTexture.h>

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmNode.h>
#include <CSD/Manager/csdmNodeObserver.h>
#include <CSD/Manager/csdmObserverBase.h>
#include <CSD/Manager/csdmProject.h>
#include <CSD/Manager/csdmRCObject.h>
#include <CSD/Manager/csdmRCObjectImp.h>
#include <CSD/Manager/csdmRCPtr.h>
#include <CSD/Manager/csdmRCPtrAbs.h>
#include <CSD/Manager/csdmResourceBase.h>
#include <CSD/Manager/csdmScene.h>
#include <CSD/Manager/csdmSceneObserver.h>
#include <CSD/Manager/csdmSubjectBase.h>

#include <Sonic/DX_PATCH.h>
#include <Sonic/Animation/AnimationContext.h>
#include <Sonic/Camera/Camera.h>
#include <Sonic/CSD/CsdDatabaseWrapper.h>
#include <Sonic/CSD/CsdProject.h>
#include <Sonic/CSD/GameObjectCSD.h>
#include <Sonic/Debug/DebugStageSelectMenu.h>
#include <Sonic/FxPipeline/FxSceneRenderer.h>
#include <Sonic/FxPipeline/FxScheduler.h>
#include <Sonic/FxPipeline/Jobs/FxJob.h>
#include <Sonic/FxPipeline/Jobs/FxJobBase.h>
#include <Sonic/FxPipeline/Jobs/AlternativeDepthOfField/FxAlternativeDepthOfField.h>
#include <Sonic/FxPipeline/Jobs/BloomGlare/FxBloomGlare.h>
#include <Sonic/FxPipeline/Jobs/ColorCorrection/FxColorCorrection.h>
#include <Sonic/FxPipeline/Jobs/CrossFade/FxCrossFade.h>
#include <Sonic/FxPipeline/Jobs/RenderGameScene/FxRenderGameScene.h>
#include <Sonic/FxPipeline/Jobs/RenderScene/FxRenderScene.h>
#include <Sonic/FxPipeline/Jobs/ShadowMap/FxShadowMap.h>
#include <Sonic/FxPipeline/Jobs/ToneMapping/FxToneMapping.h>
#include <Sonic/Message/MsgAddImpulse.h>
#include <Sonic/Message/MsgAddVelocity.h>
#include <Sonic/Message/MsgDead.h>
#include <Sonic/Message/MsgGetAnimationInfo.h>
#include <Sonic/Message/MsgGetHomingAttackPosition.h>
#include <Sonic/Message/MsgGetHomingAttackPriority.h>
#include <Sonic/Message/MsgGetPosition.h>
#include <Sonic/Message/MsgGetRotation.h>
#include <Sonic/Message/MsgHitReactionPlate.h>
#include <Sonic/Message/MsgKill.h>
#include <Sonic/Message/MsgSetPosition.h>
#include <Sonic/Message/MsgSetRotation.h>
#include <Sonic/Message/MsgSetVisible.h>
#include <Sonic/Message/MsgStartHomingChase.h>
#include <Sonic/Object/ObjectBase.h>
#include <Sonic/ObjectSystem/SetObjectEntry.h>
#include <Sonic/ObjectSystem/SetObjectFactory.h>
#include <Sonic/ObjectSystem/SetObjectInfo.h>
#include <Sonic/ObjectSystem/SetObjectListener.h>
#include <Sonic/Player/Character/Base/Player.h>
#include <Sonic/Player/Character/Base/PlayerContext.h>
#include <Sonic/Player/Character/Sonic/Sonic.h>
#include <Sonic/Player/Character/Sonic/SonicContext.h>
#include <Sonic/Player/Character/SonicClassic/SonicClassic.h>
#include <Sonic/Player/Character/SonicClassic/SonicClassicContext.h>
#include <Sonic/Player/Character/SonicSp/SonicSp.h>
#include <Sonic/Player/Character/SonicSp/SonicSpContext.h>
#include <Sonic/Player/Character/Speed/PlayerSpeed.h>
#include <Sonic/Player/Character/Speed/PlayerSpeedContext.h>
#include <Sonic/Player/Character/Speed/PlayerSpeedContext.inl>
#include <Sonic/Player/Character/Speed/StateFlag.h>
#include <Sonic/Player/Character/Speed/State/PlayerSpeedStateBase.h>
#include <Sonic/Player/Character/Speed/State/PlayerSpeedStateReactionLand.h>
#include <Sonic/Player/Parameter/PlayerCommonParameter.h>
#include <Sonic/Player/Parameter/PlayerParameter.h>
#include <Sonic/Player/Parameter/PlayerSpeedParameter.h>
#include <Sonic/Player/Parameter/SonicClassicParameter.h>
#include <Sonic/Player/Parameter/SonicParameter.h>
#include <Sonic/Player/Parameter/SonicSpParameter.h>
#include <Sonic/System/ApplicationDocument.h>
#include <Sonic/System/GameDocument.h>
#include <Sonic/System/GameObject.h>
#include <Sonic/System/GameObject3D.h>
#include <Sonic/System/GameObjectModel.h>
#include <Sonic/System/GameObjectRigidBody.h>
#include <Sonic/System/InputState.h>
#include <Sonic/System/MatrixNodeTransform.h>
#include <Sonic/System/PadState.h>
#include <Sonic/System/World.h>
#include <Sonic/System/LightManager/LightManager.h>
#include <Sonic/System/LightManager/LocalLight.h>
#include <Sonic/System/RenderDirector/RenderDirector.h>
#include <Sonic/System/RenderDirector/RenderDirectorFxPipeline.h>
#include <Sonic/Tool/EditParam/EditParam.h>
#include <Sonic/Tool/EditParam/ParamBase.h>
#include <Sonic/Tool/EditParam/ParamBool.h>
#include <Sonic/Tool/EditParam/ParamTypeList.h>
#include <Sonic/Tool/EditParam/ParamValue.h>
#include <Sonic/Tool/ParameterEditor/AbstractParameter.h>
#include <Sonic/Tool/ParameterEditor/AbstractParameterNode.h>
#include <Sonic/Tool/ParameterEditor/ParameterCategory.h>
#include <Sonic/Tool/ParameterEditor/ParameterFile.h>
#include <Sonic/Tool/ParameterEditor/ParameterGroup.h>

// Lost World/Forces style namespace aliases
namespace hh = Hedgehog;
namespace Hedgehog
{
    namespace base = Base;
    namespace db = Database;
    namespace fx = FxRenderFramework;
    namespace math = Math;
    namespace mr = Mirage;
    namespace mot = Motion;
    namespace fnd = Universe;
    namespace ygg = Yggdrasill;
}

namespace app = Sonic;
