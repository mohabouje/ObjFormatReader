//
// Created by Mohammed Boujemaoui on 13/11/2017.
//

#ifndef OBJFORMATREADER_STRUCTS_H
#define OBJFORMATREADER_STRUCTS_H

#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT_64
#else
#define ENVIRONMENT_32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT_64
#else
#define ENVIRONMENT_32
#endif
#endif


#ifdef ENVIRONMENT_64
using sample = double;
#else
using sample = float;
#endif



#endif //OBJFORMATREADER_STRUCTS_H
