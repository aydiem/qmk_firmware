/* Copyright 2019 Fate
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define ___ KC_NO

#define LAYOUT( \
    k00, k10, k01, k11, k02, k12, k03,           k04, k14, k05, k15, k06, k16, k07, \
    k20, k30, k21, k31, k22, k32, k23,           k24, k34, k25, k35, k26, k36, k27, \
    k40, k50, k41, k51, k42, k52, k43,           k44, k54, k45, k55, k46, k56, k47, \
    k60, k70, k61, k71, k62, k72, k63,           k64, k74, k65, k75, k66, k76, k67, \
    k80, k90, k81, k91, k82, k92, k83, k53, k73, k84, k94, k85, k95, k86, k96, k87, \
    kA0, k33, kA1, k13, kA2, k97, kA3, k77, k93, kA4, k57, kA5, k37, kA6, k17, kA7 \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06, k07 }, \
    { k10, k11, k12, k13, k14, k15, k16, k17 }, \
    { k20, k21, k22, k23, k24, k25, k26, k27 }, \
    { k30, k31, k32, k33, k34, k35, k36, k37 }, \
    { k40, k41, k42, k43, k44, k45, k46, k47 }, \
    { k50, k51, k52, k53, k54, k55, k56, k57 }, \
    { k60, k61, k62, k63, k64, k65, k66, k67 }, \
    { k70, k71, k72, k73, k74, k75, k76, k77 }, \
    { k80, k81, k82, k83, k84, k85, k86, k87 }, \
    { k90, k91, k92, k93, k94, k95, k96, k97 }, \
    { kA0, kA1, kA2, kA3, kA4, kA5, kA6, kA7 }, \
}

