#pragma once
#include <Hedgehog/Base/Type/hhSharedString.h>
namespace Hedgehog::Glitter
{
	struct Color
	{
		uint8_t B;
		uint8_t G;
		uint8_t R;
		uint8_t A;
	};

	struct ParticleParameter
	{
		Hedgehog::Base::CSharedString Name;
		BB_INSERT_PADDING(0xFC);
		int Field100;
		int Field104;
		BB_INSERT_PADDING(0x8);
		Color Color;
		BB_INSERT_PADDING(0x70);
		int Field184;
		int Field188;
		int Field18C;
		Hedgehog::Base::CSharedString Material;
		int Field194;
		int Field198;
		BB_INSERT_PADDING(0x10);
		Hedgehog::Base::CSharedString ModelReference;
		int Field1B0;
		int Field1B4;
	};

	class CParticle
	{
	public:
		BB_INSERT_PADDING(0xC);
		boost::shared_ptr<ParticleParameter>  m_spParticleParam;
		BB_INSERT_PADDING(0xD8);
		virtual ~CParticle() = 0;
	};
	class CEmitter
	{
	public:
		BB_INSERT_PADDING(0x14);
		hh::list<boost::shared_ptr<CParticle>> m_ParticleList;
		BB_INSERT_PADDING(0x112);
		float m_Field138;
		float m_Field13C;
		float m_Field140;
		int m_Field144;

		virtual ~CEmitter() = 0;
	};

	class CEffect
	{
	public:

		BB_INSERT_PADDING(0xC);
		int m_Field10;
		int m_Field14;
		hh::list<boost::shared_ptr<CEmitter>> m_EmitterList;
		int m_Field24;
		BB_INSERT_PADDING(0x38);
		float m_Field60;
		BB_INSERT_PADDING(0x4C);
		float m_FieldB0;
		int m_FieldB4;

		virtual ~CEffect() = 0;
	};
	class CHandle
	{
	public:
		BB_INSERT_PADDING(0xC);
		hh::list<boost::shared_ptr<CEffect>> m_EffectList;
		BB_INSERT_PADDING(0x84);
		Hedgehog::Base::CSharedString m_ParticleFileName;
		BB_INSERT_PADDING(0x26);

		boost::shared_ptr<CParticle> GetParticleByName(const Hedgehog::Base::CSharedString& in_rName)
		{
			for (const auto& effect : m_EffectList)
			{
				for (const auto& emitter : effect->m_EmitterList)
				{
					for (const auto& particle : emitter->m_ParticleList)
					{
						if (particle->m_spParticleParam->Name == in_rName)
						{
							return particle;
						}
					}
				}
			}
			return nullptr;
		}
		virtual ~CHandle() = 0;
	};


	BB_ASSERT_OFFSETOF(ParticleParameter, Name, 0x0);
	BB_ASSERT_OFFSETOF(ParticleParameter, Field100, 0x100);
	BB_ASSERT_OFFSETOF(ParticleParameter, Field104, 0x104);
	BB_ASSERT_OFFSETOF(ParticleParameter, Color, 0x110);
	BB_ASSERT_OFFSETOF(ParticleParameter, Field184, 0x184);
	BB_ASSERT_OFFSETOF(ParticleParameter, Field188, 0x188);
	BB_ASSERT_OFFSETOF(ParticleParameter, Field18C, 0x18C);
	BB_ASSERT_OFFSETOF(ParticleParameter, Material, 0x190);
	BB_ASSERT_OFFSETOF(ParticleParameter, Field194, 0x194);
	BB_ASSERT_OFFSETOF(ParticleParameter, Field198, 0x198);
	BB_ASSERT_OFFSETOF(ParticleParameter, ModelReference, 0x1AC);
	BB_ASSERT_OFFSETOF(ParticleParameter, Field1B0, 0x1B0);
	BB_ASSERT_OFFSETOF(ParticleParameter, Field1B4, 0x1B4);

	BB_ASSERT_OFFSETOF(CParticle, m_spParticleParam, 0x10);
	BB_ASSERT_SIZEOF(CParticle, 0xF0);

	BB_ASSERT_OFFSETOF(CEmitter, m_ParticleList, 0x18);
	BB_ASSERT_OFFSETOF(CEmitter, m_Field138, 0x138);
	BB_ASSERT_OFFSETOF(CEmitter, m_Field13C, 0x13C);
	BB_ASSERT_OFFSETOF(CEmitter, m_Field140, 0x140);
	BB_ASSERT_OFFSETOF(CEmitter, m_Field144, 0x144);

	BB_ASSERT_OFFSETOF(CEffect, m_Field10, 0x10);
	BB_ASSERT_OFFSETOF(CEffect, m_Field14, 0x14);
	BB_ASSERT_OFFSETOF(CEffect, m_EmitterList, 0x18);
	BB_ASSERT_OFFSETOF(CEffect, m_Field24, 0x24);
	BB_ASSERT_OFFSETOF(CEffect, m_Field60, 0x60);
	BB_ASSERT_OFFSETOF(CEffect, m_FieldB0, 0xB0);
	BB_ASSERT_OFFSETOF(CEffect, m_FieldB4, 0xB4);

	BB_ASSERT_OFFSETOF(CHandle, m_EffectList, 0x10);
	BB_ASSERT_OFFSETOF(CHandle, m_ParticleFileName, 0xA0);
}