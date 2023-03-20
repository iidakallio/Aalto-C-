#include "transcript.hpp"
#include <algorithm>


void TranscriptRegistry::Add(const Transcript& transcript) {
    transcripts_.push_back(transcript);
}

void TranscriptRegistry::RemoveById(const std::string& id){
    /*for (auto it : transcripts_) {
        if (it.student_id == id)  {
            
            transcripts_.remove(it);
            return;
        }

    }*/
    transcripts_.erase(
        std::remove_if(transcripts_.begin(), transcripts_.end(),[&](const auto &it) 
        { 
            return it.student_id == id; 
        }
        )
    );
}


std::list<Transcript>::const_iterator TranscriptRegistry::FindTranscript(const std::string& id) const{
    return std::find_if(
        transcripts_.begin(), transcripts_.end(), [&](const auto &it) { 
            return it.student_id == id; 
        });
}
std::list<std::pair<std::string, size_t>> TranscriptRegistry::FindCourseResults(const std::string &course_name) const{

    std::list<std::pair<std::string, size_t>> gradelist = {};
    for (auto it: transcripts_) {
        for (auto gr : it.grades) {
           if (gr.first == course_name){
            gradelist.push_back(make_pair(it.student_id, gr.second));
           } 
        }


    }
    return gradelist;
}

const std::list<Transcript> TranscriptRegistry::GetTranscripts() const{
    return transcripts_;
}