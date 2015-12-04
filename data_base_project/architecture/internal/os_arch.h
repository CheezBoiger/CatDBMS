/*
* Operating System Architecture check.
*
* Copyright (c) 2015 Mario Garcia <alexander.garcia18@yahoo.com>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
* USA
*
*/

/*
	COOL CAT ARTWORK PROVIDED BY GLENDA MOORE
	Website: http://user.xmission.com/~emailbox/ascii_cats.htm
	

		          *     ,MMM8&&&.            *
		               MMMM88&&&&&    .
		              MMMM88&&&&&&&
		  *           MMM88&&&&&&&&
	 	              MMM88&&&&&&&&
					  'MMM88&&&&&&'
	                	'MMM8&&&'      *
		         /\/|_      __/\\
		        /    -\    /-   ~\  .              '
		        \    = Y =T_ =   /
	  	         )==*(`     `) ~ \
		        /     \     /     \
		        |     |     ) ~   (
		       /       \   /     ~ \
	 	       \       /   \~     ~/
		jgs_/\_/\__  _/_/\_/\__~__/_/\_/\_/\_/\_/\_
		|  |  |  | ) ) |  |  | ((  |  |  |  |  |  |
		|  |  |  |( (  |  |  |  \\ |  |  |  |  |  |
		|  |  |  | )_) |  |  |  |))|  |  |  |  |  |
		|  |  |  |  |  |  |  |  (/ |  |  |  |  |  |
		|  |  |  |  |  |  |  |  |  |  |  |  |  |  |


*/
/*
          M.                                         .:M
           MMMM.                                   .:MMMM
           MMMMMMMM                             .:MMMMMMM
           :MMHHHMMMMHMM.  .:MMMMMMMMM:.      .:MMHHMHMM:
            :MMHHIIIHMMMM.:MMHHHHIIIHHMMMM. .:MMHIHIIHHM:
             MMMHIIIIHHMMMIIHHMHHIIIIIHHMMMMMMHHHIIIIHHM:
             :MMHIIIIIHMMMMMMMHHIIIIIIHHHMMMMMHHII:::IHM.
              MH:I:::IHHMMMMMHHII:::IIHHMMMHHHMMM:I:IHMM
              :MHI:HHIHMMHHIIHII::.::IIHMMHHIHHMMM::HMM:
               MI::HHMMIIM:IIHII::..::HM:MHHII:::IHHMM:
               MMMHII::..:::IHMMHHHMHHMMI:::...::IHM:
               :MHHI::....::::HMMMMMMHHI::.. ..:::HM:
                :MI:.:MH:.....:HMMMMHHMIHMMHHI:HH.:M
                M:.I..MHHHHHMMMIHMMMMHMMHHHHHMMH:.:M.
                M:.H..H  I:HM:MHMHI:IM:I:MM::  MMM:M:
                :M:HM:.M I:MHMIIMMIIHM I:MM::.:MMI:M.
                'M::MM:IMH:MMII MMHIMHI :M::IIHMM:MM
                 MH:HMMHIHMMMMMMHMMIMHIIHHHHIMMHHMM
                  MI:MMMMHI:::::IMM:MHI:::IMMMMHIM
                  :IMHIHMMMMMM:MMMMMHHHHMMMHI:M
                    HI:IMIHMMMM:MMMMMMHHHMI:.:M      .....
        ............M::..:HMMMMIMHIIHMMMMHII:M:::''''
            ....:::MHI:.:HMMMMMMMMHHHMHHI::M:::::::''''''
           ''   ...:MHI:.::MMHHHMHMIHMMMMHH.MI..........
              ''  ...MHI::.::MHHHHIHHMM:::IHM           '''
                 '  IMH.::..::HMMHMMMH::..:HM:
                   :M:.H.IHMIIII::IIMHMMM:H.MH
                    IMMMH:HI:MMIMI:IHI:HIMIHM:
                  .MMI:.HIHMIMI:IHIHMMHIHI:MIM.
                 .MHI:::HHIIIIIHHI:IIII::::M:IM.
                .MMHII:::IHIII::::::IIIIIIHMHIIM
                MHHHI::.:IHHII:::.:::IIIIHMHIIHM:
               MHHHII::..::MII::.. ..:IIIHHHII:IM.
              .MHHII::....:MHII::.  .:IHHHI::IIHMM.
              MMHHII::.....:IHMI:. ..:IHII::..:HHMM
              MHHII:::......:IIHI...:IHI::.....::HM:
             :MMH:::........ ...::..::....  ...:IHMM
             IMHIII:::..........     .........::IHMM.
             :MHIII::::......          .......::IHMM:
              MHHIII::::...             ......::IHMM:
              IMHHIII:::...             .....::IIHMM,
              :MHHIII:::I:::...     ....:::I:::IIHMM
               MMHHIII::IHI:::...........:::IIH:IHMM
               :MMHHII:IIHHI::::::.....:::::IH:IHMIM
                MMMHHII:IIHHI:::::::::::::IHI:IIHM:M.
                MMMHHIII::IHHII:::::::::IHI:IIIHMM:M:
                :MMHHHIII::IIIHHII::::IHI..IIIHHM:MHM
                :MMMHHII:..:::IHHMMHHHHI:IIIIHHMM:MIM
                .MMMMHHII::.:IHHMM:::IIIIIIHHHMM:MI.M
              .MMMMHHII::.:IHHMM:::IIIIIIHHHMM:MI.M
            .MMMMHHMHHII:::IHHMM:::IIIIIHHHHMM:MI.IM.
           .MMHMMMHHHII::::IHHMM::I&&&IHHHHMM:MMH::IM.
          .MMHHMHMHHII:::.::IHMM::IIIIHHHMMMM:MMH::IHM
          :MHIIIHMMHHHII:::IIHMM::IIIHHMMMMM::MMMMHHHMM.
          MMHI:IIHMMHHHI::::IHMM:IIIIHHHMMMM:MMMHI::IHMM.
          MMH:::IHMMHHHHI:::IHMM:IIIHHHHMMMM:MMHI:.:IHHMM.
          :MHI:::IHMHMHHII::IHMM:IIIHHHMMMMM:MHH::.::IHHM:
          'MHHI::IHMMHMHHII:IHMM:IIHHHHMMMM:MMHI:...:IHHMM.
           :MHII:IIHMHIHHIIIIHMM:IIHHHHMMMM:MHHI:...:IIHMM:
           'MHIII:IHHMIHHHIIHHHMM:IHHHMMMMM:MHHI:..::IIHHM:
            :MHHIIIHHMIIHHHIHHHMM:HHHHMMMMM:MHII::::IIIHHMM
             MHHIIIIHMMIHHHIIHHMM:HHHHMMMM:MMHHIIHIIIIIHHMM.
             'MHHIIIHHMIIHHIIIHMM:HHHMMMMH:MHHMHII:IIIHHHMM:
              'MHHIIIHMMIHHHIHHMM:HHHMMMHH:MMIMMMHHHIIIHHMM:
               'MHHIIHHMIHHHHHMMM:HHHMMMH:MIMMMMMMMMMMHIHHM:
                'MHIIIHMMIHHHHHMM:HHHMMMH:IMMMMMHHIHHHMMHHM'
                 :MHHIIHMIHHHHHMM:HHHMMMM:MMHMMHIHMHI:IHHHM
                  MHHIIHM:HHHHHMM:HHHMMMM:MMMHIHHIHMM:HHIHM
                   MHHIHM:IHHHHMM:HHHHMM:MMHMIIHMIMMMHMHIM:
                   :MHIHMH:HHHHMM:HHHHMM:MMHIIHMIIHHMMHIHM:
                    MMHHMH:HHHHMM:HHHHMM:MHHIHMMIIIMMMIIHM'
                    'MMMMH:HHHHMM:HHHMM:MHHHIMMHIIII::IHM:
                     :MMHM:HHHHMM:HHHMM:MHIHIMMHHIIIIIHM:
                      MMMM:HHHHMM:HHHHM:MHHMIMMMHHHIHHM:MMMM.
                      :MMM:IHHHMM:HHHMM:MHHMIIMMMHHMM:MMMMMMM:
                      :MMM:IHHHM:HHHHMM:MMHHHIHHMMM:MMMMMMMMMM
                       MHM:IHHHM:HHHMMM:MMHHHHIIIMMIIMMMMMMMMM
                       MHM:HHHHM:HHHMMM:HMMHHHHHHHHHMMMMMMMMM:
                    .MI:MM:MHHMM:MHMMHMHHMMMMHHHHHHHMMMMMMMMM'
                   :IM:MMIM:M:MM:MH:MM:MH:MMMMMHHHHHMMMMMMMM'
                   :IM:M:IM:M:HM:IMIHM:IMI:MMMMMHHHMMMMMM:'
                    'M:MHM:HM:MN:HMIHM::M'   '::MMMMMMM:'
                       'M'HMM'M''M''HM'I'
*/
#ifndef _OS_ARCH_H_
#define _OS_ARCH_H_

#pragma once

// Define Windows operating systems, default _WIN32 bit compatible with 64-bit OS Windows too!
#ifdef _WIN32
 #define _DB_CAT_WINDOWS
#elif defined(__CYGWIN__)
 #define _DB_CAT_CYGWIN
#elif defined(__OpenBSD__)
 #define _DB_CAT_BSD
#elif defined(__APPLE__) && defined(__MACH__)
 #define _DB_CAT_APPLE
#elif defined(__linux__)
 #define _DB_CAT_LINUX
#elif defined(__unix__)
 #define _DB_CAT_UNIX
#else
 #error Software is not compatible! What the hell kind of OS are you running?
#endif /* _WIN32 */


#endif /* _OS_ARCH_H_ */
