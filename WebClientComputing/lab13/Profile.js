import withLogin from './withLogin'; // 그냥 리액트 임포트는 생략..
import withLoading from './withLoading';
import withError from './withError';
import { compose } from 'redux';
import MyCompose from './MyCompose';
 
const Profile = ({user}) => {
  return (
    <div>
      	{`(회원이름) ${user}`}
    </div>
  )
}
 
// export default withLogin(withLoading('로딩 중입니다!!!')(withError(Profile))); 
//export default compose(withLogin, withLoading('로딩 중입니다!!!'), withError)(Profile); 
export default MyCompose(withLogin, withLoading('로딩 중입니다!!!'), withError)(Profile); 
