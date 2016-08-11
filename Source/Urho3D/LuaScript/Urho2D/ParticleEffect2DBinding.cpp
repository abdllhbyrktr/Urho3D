//
// Copyright (c) 2008-2016 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifdef URHO3D_URHO2D

#include "../../Precompiled.h"

#include "../../Urho2D/ParticleEffect2D.h"
#include "../../LuaScript/LuaScriptUtils.h"

#include <kaguya.hpp>

namespace Urho3D
{

KAGUYA_MEMBER_FUNCTION_OVERLOADS(ParticleEffect2DClone, ParticleEffect2D, Clone, 0, 1);

void RegisterParticleEffect2D(kaguya::State& lua)
{
    using namespace kaguya;

    // [Enum] EmitterType2D
    lua["EMITTER_TYPE_GRAVITY"] = EMITTER_TYPE_GRAVITY;
    lua["EMITTER_TYPE_RADIAL"] = EMITTER_TYPE_RADIAL;

    // [Class] ParticleEffect2D : Resource
    lua["ParticleEffect2D"].setClass(UserdataMetatable<ParticleEffect2D, Resource>()
        // [Constructor] ParticleEffect2D()
        .addStaticFunction("new", &CreateObject<ParticleEffect2D>)

        // [Method] SharedPtr<ParticleEffect2D> Clone(const String& cloneName = String::EMPTY) const
        .addFunction("Clone", ParticleEffect2DClone())
         );
}
}

#endif