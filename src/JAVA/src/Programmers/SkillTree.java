package Programmers;

class SkillTree {
	public int solution(String skill, String[] skill_trees) {
		int answer = 0;
		String [] skillArray = skill.split("");
		for(int i = 0; i < skill_trees.length; i++) {
			boolean flag = true;
			boolean realflag = true;
			int idx = 0;
			for(int j = 0; j < skillArray.length; j++) {
				String targetStr = skillArray[j];
				String [] tempSkillTreeArray = skill_trees[i].split("");
				for(int z = 0 ; z < tempSkillTreeArray.length; z++) {
					if(targetStr.equals(tempSkillTreeArray[z])) {
						if(flag == false ) {realflag = false;}
						if(idx == 0) {
							idx = z;
							break;
						} else {
							if(idx < z ) {
								idx = z;
								break;
							} else {
								realflag = false;
								break;
							}
						}
					} else if(z == tempSkillTreeArray.length -1 && !targetStr.equals(tempSkillTreeArray)) {
						flag = false;

					}
				}


			}
			if(realflag) answer ++;
		}
		return answer;
	}
}