#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/hhRefCountObject.h>
#include <Hedgehog/Base/Container/hhList.h>
#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/Container/hhTree.h>
#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Base/Platform/D3D9/hhCriticalSectionD3D9.h>
#include <Hedgehog/Base/System/hhAllocator.h>
#include <Hedgehog/Base/System/hhSymbol.h>
#include <Hedgehog/Base/Thread/hhHolder.h>
#include <Hedgehog/Base/Thread/hhHolderBase.h>
#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>
#include <Hedgehog/Base/Type/hhCowData.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Database/System/hhArchiveDatabaseLoader.h>
#include <Hedgehog/Database/System/hhDatabase.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>
#include <Hedgehog/Database/System/hhDatabaseLoader.h>
#include <Hedgehog/Database/System/hhRawData.h>
#include <Hedgehog/FxRenderFramework/hhDrawInstanceParam.h>
#include <Hedgehog/FxRenderFramework/hhScreenRenderParam.h>
#include <Hedgehog/MirageCore/Camera/hhCamera.h>
#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.h>
#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNodeListener.h>
#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNodeTransform.h>
#include <Hedgehog/MirageCore/Misc/hhDirector.h>
#include <Hedgehog/MirageCore/Misc/hhInstanceInfo.h>
#include <Hedgehog/MirageCore/Misc/hhLightManager.h>
#include <Hedgehog/MirageCore/Misc/hhRenderingDevice.h>
#include <Hedgehog/MirageCore/Misc/hhRenderingInfrastructure.h>
#include <Hedgehog/MirageCore/Misc/hhStaticLightContext.h>
#include <Hedgehog/MirageCore/Renderable/hhElement.h>
#include <Hedgehog/MirageCore/Renderable/hhRenderable.h>
#include <Hedgehog/MirageCore/Renderable/hhSingleElement.h>
#include <Hedgehog/MirageCore/RenderData/hhLightData.h>
#include <Hedgehog/MirageCore/RenderData/hhLightListData.h>
#include <Hedgehog/MirageCore/RenderData/hhMirageDatabaseWrapper.h>
#include <Hedgehog/MirageCore/RenderData/hhPictureData.h>
#include <Hedgehog/MirageCore/RenderData/hhPixelShaderData.h>
#include <Hedgehog/MirageCore/RenderData/hhVertexShaderData.h>
#include <Hedgehog/MotionCore/MotionData/hhLightMotionData.h>
#include <Hedgehog/MotionCore/MotionData/hhMotionDatabaseWrapper.h>
#include <Hedgehog/Universe/Engine/hhMessage.h>
#include <Hedgehog/Universe/Engine/hhMessageActor.h>
#include <Hedgehog/Universe/Engine/hhMessageManager.h>
#include <Hedgehog/Universe/Engine/hhMessageProcess.h>
#include <Hedgehog/Universe/Engine/hhParallelJob.h>
#include <Hedgehog/Universe/Engine/hhStateMachine.h>
#include <Hedgehog/Universe/Engine/hhStateMachineBase.h>
#include <Hedgehog/Universe/Engine/hhStateMachineMessageReceiver.h>
#include <Hedgehog/Universe/Engine/hhUpdateInfo.h>
#include <Hedgehog/Universe/Engine/hhUpdateManager.h>
#include <Hedgehog/Universe/Engine/hhUpdateUnit.h>
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

#include <Sonic/DX_PATCH.h>
#include <Sonic/Camera/Camera.h>
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
#include <Sonic/System/ApplicationDocument.h>
#include <Sonic/System/GameDocument.h>
#include <Sonic/System/GameObject.h>
#include <Sonic/System/GameObject3D.h>
#include <Sonic/System/GameObjectModel.h>
#include <Sonic/System/GameObjectRigidBody.h>
#include <Sonic/System/InputState.h>
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
