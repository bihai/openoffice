/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



// MARKER(update_precomp.py): autogen include statement, do not remove
#include "precompiled_tools.hxx"

#include <tools/fsys.hxx>
#include <tools/stream.hxx>
#include <sstring.hxx>

int
#ifdef WNT
__cdecl
#endif
main( int argc, char **argv )
{
	String aString;
	aString = "*.*";
	Dir aDir(aString);
	SvFileStream aFile;
	SvFileStream aSortedFile;

	StringList *pList = new StringList;
	SStringList *pSortedList = new SStringList;
	ULONG nCount = aDir.Count();

	for ( ULONG i=0; i<nCount; i++ )
	{
		aString = aDir[i].GetName();
		pList->Insert( new String( aString ), LIST_APPEND );
		pSortedList->PutString( new String( aString ));
	}

	aFile.Open( "test.dir", STREAM_WRITE );
	for ( ULONG j=0; j<nCount; j++ )
	{
		aFile.WriteLine( *pList->GetObject(j) );
	}
	aFile.Close();


	aSortedFile.Open( "stest.dir", STREAM_WRITE );
	for ( ULONG k=0; k<nCount; k++ )
	{
		aSortedFile.WriteLine( *pSortedList->GetObject(k) );
	}
	if ( pSortedList->IsString( new String("bloedString")) != NOT_THERE )
		aSortedFile.WriteLine( "Fehler !" );
	if ( pSortedList->IsString( new String(".")) == NOT_THERE )
		aSortedFile.WriteLine( "Fehler ?!?" );
	aSortedFile.Close();

	delete pList;
	delete pSortedList;
	return 0;
}

	
