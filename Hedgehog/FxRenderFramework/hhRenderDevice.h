#pragma once

namespace Hedgehog::Mirage
{
    class CRenderingDevice;
    class CRenderingInfrastructure;
}

namespace Hedgehog::FxRenderFramework
{
    struct SRenderDevice
    {
        Mirage::CRenderingDevice* pRenderingDevice;
        Mirage::CRenderingInfrastructure* pRenderingInfrastructure;
    };
}